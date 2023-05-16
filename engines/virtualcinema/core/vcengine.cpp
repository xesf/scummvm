/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/scummsys.h"
 
#include "common/config-manager.h"
#include "common/debug.h"
#include "common/debug-channels.h"
#include "common/error.h"
#include "gui/EventRecorder.h"
#include "common/file.h"
#include "common/fs.h"
 
#include "graphics/cursorman.h"
#include "engines/util.h"

#include "vcengine.h"
#include "eventHandler.h"
 
namespace VirtualCinema {
 
VCEngine::VCEngine(OSystem *syst)
    : Engine(syst), _console(nullptr) {
    _rnd = new Common::RandomSource("VirtualCinema");

    Graphics::PixelFormat pixelFormat = _system->getSupportedFormats().front();
    CursorMan.showMouse(true);

    initGraphics(640, 480, &pixelFormat);
 
    _console = new Console(this);
    _video = new VideoManager(this);
}
 
VCEngine::~VCEngine() {
    delete _rnd;
}

void VCEngine::fillScreen(uint32 col) {
    _system->fillScreen(col);
}

Common::Error VCEngine::run() {    
    VCEvent mountEvt(EVENT_VC_MOUNT);
    if (_handler) {
        _handler->handleEvent(mountEvt);
    }

    debug("VCEngine::init");

    while (!shouldQuit()) {
        handleEvents();
    }

    if (_handler) {
        VCEvent deinit(EVENT_VC_UNMOUNT);
        _handler->handleEvent(deinit);
    }

    return Common::kNoError;
}

Common::Error VCEngine::handleEvents() {
    VCEvent event;
    while (_system->getEventManager()->pollEvent(event)) {
        switch (event.type) {
        default:
            break;

        case Common::EVENT_KEYDOWN:
            if (_handler) {
                _handler->handleEvent(event);
            }
            break;

        case Common::EVENT_KEYUP:
            if (_handler) {
                _handler->handleEvent(event);
            }
            break;

        case Common::EVENT_MOUSEMOVE:
        case Common::EVENT_LBUTTONDOWN:
        case Common::EVENT_LBUTTONUP:
        case Common::EVENT_RBUTTONDOWN:
        case Common::EVENT_RBUTTONUP:
        case Common::EVENT_MBUTTONUP:
        case Common::EVENT_MBUTTONDOWN:
            if (_handler) {
                _handler->handleEvent(event);
            }
            break;

        case Common::EVENT_QUIT:
            quitGame();
            break;
        }
    }
    
    VCEvent updateEvt(EVENT_VC_UPDATE);
    if (_handler) {
        _handler->handleEvent(updateEvt);
    }
    
    _system->updateScreen();
    _system->delayMillis(10);

    return Common::kNoError;
}

void VCEngine::switchEventHandler(EventHandler *handler) {
    if (handler == NULL) {
        warning("VCEngine::switchMessageHandler] NULL handler parameter");
    }

    if (_handler != NULL) {
        VCEvent deinit(EVENT_VC_UNMOUNT);
        _handler->handleEvent(deinit);
        delete _handler;
    }

    // TODO in-game menu

    _handler = handler;

    VCEvent init(EVENT_VC_MOUNT);
    if (_handler)
        _handler->handleEvent(init);
}

void VCEngine::notifyEvent(VCEventType type, int32 param1, int32 param2) {
    if (_handler == NULL)
        error("VCEngine::notifyEvent Invalid NULL handler");

    VCEvent event(type, param1, param2);
    _handler->handleEvent(event);
}
 
} // End of namespace VirtualCinema

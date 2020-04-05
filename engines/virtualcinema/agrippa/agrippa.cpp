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

#include "console.h"
#include "video.h"
#include "agrippa.h"
#include "eventHandler.h"
#include "intro.h"

#include "nodes/node.h"
 
namespace VirtualCinema {
 
AgrippaEngine::AgrippaEngine(OSystem *syst)
 : Engine(syst), _console(nullptr) {
     _rnd = new Common::RandomSource("AgrippaEngine");
     
     const Common::FSNode gameDataDir(ConfMan.get("path"));
     SearchMan.addSubDirectoryMatching(gameDataDir, "xg");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xn");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xs");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xt");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xv");
 
    // Common debug channels
    DebugMan.addDebugChannel(kDebugLevelMain, "Main", "Generic debug level");
    DebugMan.addDebugChannel(kDebugLevelResources, "Resources", "Resources debugging");
 
    debug("AgrippaEngine::AgrippaEngine");
}
 
AgrippaEngine::~AgrippaEngine() {
    debug("AgrippaEngine::~AgrippaEngine");
    _handler = NULL;
    delete _rnd;
    DebugMan.clearAllDebugChannels();
}

void AgrippaEngine::fillScreen(uint32 col) {
    _system->fillScreen(col);
}

Common::Error AgrippaEngine::run() {
    Graphics::PixelFormat pixelFormat = Graphics::PixelFormat(4, 8, 8, 8, 8, 8, 16, 24, 0); // 24bpp

    initGraphics(640, 480, &pixelFormat);
 
    _console = new Console(this);
    _video = new VideoManager(this);
    
    _intro = new Intro(this);
    _menu = new Menu(this);
    
    CursorMan.showMouse(true);
    
    _handler = _intro;
    
    AgrippaEvent mountEvt(EVENT_AGRIPPA_MOUNT);
    if (_handler) {
        _handler->handleEvent(mountEvt);
    }

    debug("AgrippaEngine::init");

    while (!shouldQuit()) {
        handleEvents();
    }

    return Common::kNoError;
}

Common::Error AgrippaEngine::handleEvents() {
    AgrippaEvent event;
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
    
    AgrippaEvent updateEvt(EVENT_AGRIPPA_UPDATE);
    if (_handler) {
        _handler->handleEvent(updateEvt);
    }
    
    _system->updateScreen();
    _system->delayMillis(10);

    return Common::kNoError;
}

void AgrippaEngine::switchEventHandler(EventHandler *handler) {
    if (handler == NULL) {
        warning("AgrippaEngine::switchMessageHandler] NULL handler parameter");
    }

    if (_handler != NULL) {
        AgrippaEvent deinit(EVENT_AGRIPPA_UNMOUNT);
        _handler->handleEvent(deinit);
    }

    // TODO in-game menu

    _handler = handler;

    AgrippaEvent init(EVENT_AGRIPPA_MOUNT);
    if (_handler)
        _handler->handleEvent(init);
}

void AgrippaEngine::notifyEvent(AgrippaEventType type, int32 param1, int32 param2) {
    if (_handler == NULL)
        error("AgrippaEngine::notifyEvent Invalid NULL handler");

    AgrippaEvent event(type, param1, param2);
    _handler->handleEvent(event);
}
 
} // End of namespace VirtualCinema

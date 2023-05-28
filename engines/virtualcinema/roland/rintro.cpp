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
// #include "common/file.h"
// #include "common/system.h"
// #include "graphics/surface.h"
// #include "image/bmp.h"


#include "virtualcinema/core/eventHandler.h"
#include "virtualcinema/core/image.h"

#include "rintro.h"
#include "rmenu.h"

namespace VirtualCinema {

RIntro::RIntro(RolandEngine *vm): _vm(vm) {
}

RIntro::~RIntro() {
    _vm->getVideoManager()->closeVideos();
    _vm->getImageManager()->closeImages();
}

bool RIntro::mountEvent(const VCEvent &evt) {
    ImageEntryPtr intro1 = _vm->getImageManager()->show("INTRO1.RLE");
    _vm->getImageManager()->updateImages();
    _vm->_system->updateScreen();
    _vm->_system->delayMillis(1000);
    _vm->getImageManager()->removeEntry(intro1);
    _vm->getImageManager()->show("BKGND.RLE");
    _vm->getImageManager()->updateImages();

    _rockslid = _vm->getVideoManager()->play("ROCKSLID.MOV");
    _rockslid->setAutoClose(false);
    _splash = _vm->getVideoManager()->play("SPLASH.MOV");
    _splash->stop();

    return true;
}

bool RIntro::unmountEvent(const VCEvent &evt) {
    return true;
}

bool RIntro::updateEvent(const VCEvent &evt) {
    if (!_logo) {
        if ((_skip || _rockslid->endOfVideo()) && !_splash->isPlaying()) {
            _skip = false;
            _rockslid->seek(Audio::Timestamp(0, 600));
            _rockslid->stop();
            _splash->start();
        }
        if (_skip || _splash->endOfVideo()) {
            _skip = false;
            _splash->close();
            _logo =_vm->getImageManager()->show("INTRO2.RLE");
            _logo->setX(_logo->getX() - 15);
            _vm->getImageManager()->updateImages();
            _rockslid->setAutoClose(true);
            _rockslid->start();
        }
    }
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    } else {
        _vm->getImageManager()->updateImages();
    }
    if (_skip || (_logo && !_vm->getVideoManager()->isVideoPlaying())) {
        if (!_skip) {
            _vm->_system->delayMillis(2000);
        }
        _vm->fillScreen(0);
        _vm->switchEventHandler(new RMenu(_vm));
        _skip = false;
    }
    return true;
}

bool RIntro::keyEvent(const VCEvent &evt) {
    return true;
}

bool RIntro::mouseEvent(const VCEvent &evt) {
    _skip = false;
    switch (evt.type) {
    case Common::EVENT_LBUTTONDOWN:
    _skip = true;
        break;
    case Common::EVENT_RBUTTONDOWN:
    default:
        break;
    }
    
    return true;
}

}

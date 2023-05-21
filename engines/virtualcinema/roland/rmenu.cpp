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

#include "rmenu.h"

namespace VirtualCinema {

RMenu::RMenu(RolandEngine *vm): _vm(vm) {
}

RMenu::~RMenu() {
}

bool RMenu::mountEvent(const VCEvent &evt) {
    _background = _vm->getImageManager()->show("CHAPMENU.RLE");
    _chapters = _vm->getImageManager()->show("MENU-BAR.RLE");
    // _chapters->setRect(85, 130, 470, 240);
    _chapters->setRect(0, 2, 470, 240);
    _chapters->setX(85);
    _chapters->setY(130);

    return true;
}

bool RMenu::unmountEvent(const VCEvent &evt) {
    return true;
}

bool RMenu::updateEvent(const VCEvent &evt) {
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    } else {
        _vm->getImageManager()->updateImages();
    }
    return true;
}

bool RMenu::keyEvent(const VCEvent &evt) {
    return true;
}

bool RMenu::mouseEvent(const VCEvent &evt) {
    _skip = false;
    switch (evt.type) {
    case Common::EVENT_LBUTTONDOWN:
    case Common::EVENT_RBUTTONDOWN:
        _skip = true;
        break;
    default:
        break;
    }
    
    return true;
}

}

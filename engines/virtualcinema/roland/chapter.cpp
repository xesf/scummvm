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

#include "chapter.h"

namespace VirtualCinema {

Chapter::Chapter(RolandEngine *vm): _vm(vm) {
}

Chapter::~Chapter() {
}

char Chapter::getCharacterIndexLetter() {
    switch (_vm->_characterIndex) {
    case 1:
        return 'A';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'R';
    default:
    case 5:
        return 'M';
    }
}

bool Chapter::mountEvent(const VCEvent &evt) {
    _background = _vm->getImageManager()->show(Common::String::format("CHAP-%d/%c/C%d%cL.RLE", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_chapterNumber, getCharacterIndexLetter()));
    _page1 = _vm->getImageManager()->show(Common::String::format("CHAP-%d/%c/C%d%cLA-2.RLE", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_chapterNumber, getCharacterIndexLetter()));
    _page1->setX(120);
    _page1->setY(105);

    _vm->getImageManager()->updateImages();
    _vm->_system->updateScreen();

    _vm->getVideoManager()->play(Common::String::format("QT/NARC%d%c%d.MOV", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_pageNumber));

    return true;
}

bool Chapter::unmountEvent(const VCEvent &evt) {
    return true;
}

bool Chapter::updateEvent(const VCEvent &evt) {
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    } else {
        _vm->getImageManager()->updateImages();
    }
    return true;
}

bool Chapter::keyEvent(const VCEvent &evt) {
    return true;
}

bool Chapter::mouseEvent(const VCEvent &evt) {
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

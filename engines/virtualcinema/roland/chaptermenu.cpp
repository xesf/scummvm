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
#include "virtualcinema/core/video.h"

#include "chaptermenu.h"
#include "chapter.h"

namespace VirtualCinema {

ChapterMenu::ChapterMenu(RolandEngine *vm): _vm(vm) {
}

ChapterMenu::~ChapterMenu() {
    _vm->getImageManager()->closeImages();
}

bool ChapterMenu::mountEvent(const VCEvent &evt) {
    _vm->getImageManager()->show(Common::String::format("SUBMAIN/CH%d.RLE", _vm->_chapterNumber));
    _vm->getImageManager()->updateImages();

    return true;
}

bool ChapterMenu::unmountEvent(const VCEvent &evt) {
    return true;
}

bool ChapterMenu::updateEvent(const VCEvent &evt) {
    // _vm->getImageManager()->updateImages();
    if (_skip) {
        _skip = false;
        _vm->fillScreen(0);
        _vm->switchEventHandler(new Chapter(_vm));
    }
    return true;
}

bool ChapterMenu::keyEvent(const VCEvent &evt) {
    return true;
}

bool ChapterMenu::mouseEvent(const VCEvent &evt) {
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

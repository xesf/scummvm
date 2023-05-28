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
#include "common/util.h"
#include "common/file.h"
#include "graphics/surface.h"

#include "virtualcinema/core/eventHandler.h"
#include "virtualcinema/core/image.h"

#include "chapter.h"
#include "rmenu.h"


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
    case 5:
    default:
        return 'M';
    }
}

char Chapter::getPageLetter() {
    if (_vm->_characterIndex == 5) {
        return _vm->_pageNumber + '@';
    }
    return _vm->_pageNumber + '0';
}

void Chapter::switchPage() {
    Common::String pagePath;
    
    if (_vm->_characterIndex == 5 && _vm->_pageNumber == 1) {
        pagePath = Common::String::format("CHAP-%d/%c/C%d%cL%c-2.RLE", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_chapterNumber, getCharacterIndexLetter(), getPageLetter());
    } else {
        pagePath = Common::String::format("CHAP-%d/%c/C%d%cL%c.RLE", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_chapterNumber, getCharacterIndexLetter(), getPageLetter());
    }

    // automatically check for page boundaries
    if (_vm->_pageNumber <= _maxPageNumber) {
        Common::File file;
        if (!file.exists(pagePath)) {
            _vm->_pageNumber -= 1;
            _maxPageNumber = _vm->_pageNumber;
            pagePath = Common::String::format("CHAP-%d/%c/C%d%cL%c.RLE", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_chapterNumber, getCharacterIndexLetter(), getPageLetter());
        }
    }

    if (_page.get() != nullptr) {
        _vm->getImageManager()->removeEntry(_page);
        _page->close();
    }
    _page = _vm->getImageManager()->show(pagePath);
    _page->setX(120);
    _page->setY(105);
}

bool Chapter::mountEvent(const VCEvent &evt) {
    _prevPageNumber = _vm->_pageNumber;

    _background = _vm->getImageManager()->show(Common::String::format("CHAP-%d/%c/C%d%cL.RLE", _vm->_chapterNumber, getCharacterIndexLetter(), _vm->_chapterNumber, getCharacterIndexLetter()));
    switchPage();
    _vm->getImageManager()->updateImages();
    _vm->_system->updateScreen();
    _vm->getVideoManager()->play(Common::String::format("QT/NARC%d%c%d.MOV", _vm->_chapterNumber, getCharacterIndexLetter(), (_vm->_characterIndex == 5) ? 1 : _vm->_pageNumber));

    // _vm->getVideoManager()->resumeVideos();

    return true;
}

bool Chapter::unmountEvent(const VCEvent &evt) {
    _vm->getImageManager()->closeImages();
    _vm->getVideoManager()->closeVideos();
    return true;
}

bool Chapter::updateEvent(const VCEvent &evt) {
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    } else {
        _vm->getImageManager()->updateImages();
    }

    if (_prevPageNumber != _vm->_pageNumber) {
        _prevPageNumber = _vm->_pageNumber;
        switchPage();
        _vm->getImageManager()->updateImages();
        _vm->_system->updateScreen();
    }

    // debugging hotspots
    if (_mouseStartSet && _mouseEndSet) {
        _mouseStartSet = false;
        _mouseEndSet = false;
        Graphics::Surface *surf = _vm->_system->lockScreen();
        surf->frameRect(Common::Rect(_mousePosStart.x, _mousePosStart.y, _mousePosEnd.x, _mousePosEnd.y), 0x00FF00);
        _vm->_system->copyRectToScreen(surf->getBasePtr(0,0), surf->pitch, 0, 0, surf->w, surf->h);
        _vm->_system->unlockScreen();
        _vm->_system->updateScreen();
        debug("Mouse rect: %d, %d, %d, %d", _mousePosStart.x, _mousePosStart.y, _mousePosEnd.x, _mousePosEnd.y);
    }
    return true;
}

bool Chapter::keyEvent(const VCEvent &evt) {
    return true;
}

bool Chapter::mouseEvent(const VCEvent &evt) {
    _skip = false;
    switch (evt.type) {
    case Common::EVENT_MOUSEMOVE:
        _mousePos = evt.mouse;
        break;
    case Common::EVENT_LBUTTONDOWN:
        for (uint i = 0; i < ARRAYSIZE(_cardHotspot); i++) {
            if (_cardHotspot[i].contains(evt.mouse)) {
                if (_vm->_characterIndex == i) {
                    _vm->_characterIndex = 5;
                } else {
                    _vm->_characterIndex = i;
                }
            }
        }
        for (uint i = 0; i < ARRAYSIZE(_menuHotspot); i++) {
            if (_menuHotspot[i].contains(evt.mouse)) {
                _vm->_selectedMenu = i + 1;
            }
        }
        for (uint i = 0; i < ARRAYSIZE(_pageHotspot); i++) {
            if (_pageHotspot[i].contains(evt.mouse)) {
                if (i == 1) {
                    _vm->switchEventHandler(new RMenu(_vm));
                    break;
                }
                if (_prevPageNumber == _vm->_pageNumber) {
                    _prevPageNumber = _vm->_pageNumber;
                    if (i == 0) {
                        _vm->_pageNumber -= 1;
                    } else if (i == 2) {
                        _vm->_pageNumber += 1;
                    }
                    
                    if (_vm->_pageNumber < 1) {
                        _vm->_pageNumber = 1;
                    }
                    if (_vm->_pageNumber > _maxPageNumber) {
                        _vm->_pageNumber = _maxPageNumber;
                    }
                }
            }
        }
        break;

        // debugging hotspots
        if (_mouseStartSet && _mouseEndSet) { // reset
            _mouseStartSet = false;
            _mouseEndSet = false;
            _mousePosStart = Common::Point();
            _mousePosEnd = Common::Point();
        }
        if (_mouseStartSet && !_mouseEndSet) {
            _mousePosEnd = _mousePos;
            _mouseEndSet = true;
        }
        if (!_mouseStartSet && !_mouseEndSet) {
            _mousePosStart = _mousePos;
            _mouseStartSet = true;
        }
        break;
    default:
        break;
    }
    
    return true;
}

}

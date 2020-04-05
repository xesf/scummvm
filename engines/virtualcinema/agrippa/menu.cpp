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

#include "menu.h"
#include "eventHandler.h"

namespace VirtualCinema {

Menu::Menu(AgrippaEngine *vm): _vm(vm) {
}

Menu::~Menu() {
}

bool Menu::handleEvent(const AgrippaEvent &evt) {
    switch ((int32)evt.type) {
    default:
        break;

    case EVENT_AGRIPPA_MOUNT:
        return mountEvent(evt);
            
    case EVENT_AGRIPPA_UNMOUNT:
        return unmountEvent(evt);

    case EVENT_AGRIPPA_UPDATE:
        return updateEvent(evt);

    case Common::EVENT_KEYDOWN:
        return keyEvent(evt);

    case Common::EVENT_MOUSEMOVE:
    case Common::EVENT_LBUTTONDOWN:
        return mouseEvent(evt);

    }

    return false;
}

bool Menu::mountEvent(const AgrippaEvent &evt) {
    _intro = _vm->getVideoManager()->play("xg/49583.xmv");
    _intro.get()->moveTo(0, 0);
    
    return true;
}

bool Menu::unmountEvent(const AgrippaEvent &evt) {
    return true;
}

void Menu::mountMenu() {
    _background = _vm->getVideoManager()->play("xg/49585.xmv");
    _background.get()->moveTo(61, 103);
    _background.get()->setLooping(true);
    
    mountMenuItems(false);
    mountMenuTitle();
    
    _titleRect = _title.get()->getRect();
}

void Menu::mountMenuTitle() {
    _title = _vm->getVideoManager()->play("xg/49589.xmv");
    _title.get()->moveTo(58, 0);
    _title.get()->stop();
}

//const Audio::Timestamp &startTime, const Audio::Timestamp &endTime
void Menu::mountMenuItems(bool reloaded) {
    _menuItems = _vm->getVideoManager()->play("xg/49587.xmv");
    _menuItems.get()->moveTo(640 - 168, 0);
    if (reloaded) {
        _menuItems.get()->setBounds(Audio::Timestamp(5000, 600), _menuItems.get()->getDuration());
        _menuItems.get()->seek(Audio::Timestamp(5000, 600));
        _menuItems.get()->stop();
    } else {
        _menuItems.get()->setEndTime(Audio::Timestamp(5000, 600));
    }
}

bool Menu::updateEvent(const AgrippaEvent &evt) {
    if (!_titleRect.isEmpty()) {
        if (_title.get()->endOfVideo()) {
            mountMenuTitle();
        }
        if (_menuItems.get()->endOfVideo()) {
            mountMenuItems(true);
        }
    }
    
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    }
    
    if (!_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->stopVideos();
        mountMenu();
    }
    
    switch (_selectedMenuItem) {
    case kMenuItemNew:
        _vm->getVideoManager()->stopVideos();
        _vm->fillScreen(0);
        _vm->switchEventHandler(_vm->getGame());
        break;
    case kMenuItemLoad:
        break;
    case kMenuItemSave:
        break;
    case kMenuItemPrevious:
        break;
    case kMenuItemOptions:
        break;
    case kMenuItemHelp:
        break;

    case kMenuItemQuit:
        _vm->quitGame();
        break;

    default:
        break;
    }
    _selectedMenuItem = -1;
    
    return true;
}

bool Menu::keyEvent(const AgrippaEvent &evt) {
    return true;
}

bool Menu::mouseEvent(const AgrippaEvent &evt) {
    switch (evt.type) {
    case Common::EVENT_MOUSEMOVE:
        if (!_titleRect.isEmpty()) {
            if (_titleRect.contains(evt.mouse)) {
                if (!_title.get()->isPlaying()) {
                    _title.get()->start();
                }
            }
        }
        for (uint i = 0; i < ARRAYSIZE(_menuItemsRects); i++) {
            if (_menuItemsRects[i].contains(evt.mouse)) {
                _menuItems.get()->setBounds(_menuItemsBoundStart[i], _menuItemsBoundEnd[i]);
                _menuItems.get()->start();
            }
        }
                
        // debug("%hd %hd", evt.mouse.x, evt.mouse.y);
        break;
    case Common::EVENT_LBUTTONDOWN:
        for (uint i = 0; i < ARRAYSIZE(_menuItemsRects); i++) {
            if (_menuItemsRects[i].contains(evt.mouse)) {
                _selectedMenuItem = i;
            }
        }
        break;
    default:
        break;
    }
    
    return true;
}

}

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
    
    mountMenuItems();
    mountMenuTitle();
    
    _titleRect = _title.get()->getRect();
}

void Menu::mountMenuTitle() {
    _title = _vm->getVideoManager()->play("xg/49589.xmv");
    _title.get()->moveTo(58, 0);
    _title.get()->stop();
}

//const Audio::Timestamp &startTime, const Audio::Timestamp &endTime
void Menu::mountMenuItems() {
    _menuItems = _vm->getVideoManager()->play("xg/49587.xmv");
    _menuItems.get()->moveTo(640 - 168, 0);
    Audio::Timestamp end = _menuItems.get()->getDuration();
    _menuItems.get()->setEndTime(end - Audio::Timestamp(6000, end.framerate()));
}

bool Menu::updateEvent(const AgrippaEvent &evt) {
    if (!_titleRect.isEmpty() && _title.get()->endOfVideo()) {
        mountMenuTitle();
    }
    
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    }
    
    if (!_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->stopVideos();
        mountMenu();
    }
    
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
        break;
    default:
        break;
    }
    
    return true;
}

}

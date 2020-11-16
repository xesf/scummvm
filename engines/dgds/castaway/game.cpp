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

#include "game.h"
#include "eventHandler.h"

namespace Dgds {

Game::Game(CastawayEngine *vm): _vm(vm) {
}

Game::~Game() {
}

bool Game::handleEvent(const CastawayEvent &evt) {
    switch ((int32)evt.type) {
    default:
        break;

    case EVENT_CASTAWAY_MOUNT:
        return mountEvent(evt);
            
    case EVENT_CASTAWAY_UNMOUNT:
        return unmountEvent(evt);

    case EVENT_CASTAWAY_UPDATE:
        return updateEvent(evt);

    case Common::EVENT_KEYDOWN:
        return keyEvent(evt);

    case Common::EVENT_LBUTTONDOWN:
    case Common::EVENT_RBUTTONDOWN:
        return mouseEvent(evt);

    }

    return false;
}

bool Game::mountEvent(const CastawayEvent &evt) {
    return true;
}

bool Game::unmountEvent(const CastawayEvent &evt) {
    return true;
}

bool Game::updateEvent(const CastawayEvent &evt) {
    return true;
}

bool Game::keyEvent(const CastawayEvent &evt) {
    return true;
}

bool Game::mouseEvent(const CastawayEvent &evt) {
    switch (evt.type) {
    case Common::EVENT_LBUTTONDOWN:
    case Common::EVENT_RBUTTONDOWN:
        break;
    default:
        break;
    }
    
    return true;
}

}

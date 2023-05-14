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

#include "virtualcinema/core/vcengine.h"
#include "virtualcinema/core/eventHandler.h"

#include "scene.h"

namespace VirtualCinema {

Scene::Scene() {
}

Scene::~Scene() {
}

bool Scene::handleEvent(const VCEvent &evt) {
    switch ((int32)evt.type) {
    default:
        break;

    case EVENT_VC_MOUNT:
        return mountEvent(evt);
            
    case EVENT_VC_UNMOUNT:
        return unmountEvent(evt);

    case EVENT_VC_UPDATE:
        return updateEvent(evt);

    case Common::EVENT_KEYDOWN:
        return keyEvent(evt);

    case Common::EVENT_MOUSEMOVE:
    case Common::EVENT_LBUTTONDOWN:
        return mouseEvent(evt);

    }

    return false;
}

bool Scene::mountEvent(const VCEvent &evt) {    
    return true;
}

bool Scene::unmountEvent(const VCEvent &evt) {
    return true;
}

bool Scene::updateEvent(const VCEvent &evt) {
    return true;
}

bool Scene::keyEvent(const VCEvent &evt) {
    return true;
}

bool Scene::mouseEvent(const VCEvent &evt) {
    return true;
}

}

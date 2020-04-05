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

#include "intro.h"
#include "eventHandler.h"

namespace VirtualCinema {

Intro::Intro(AgrippaEngine *vm): _vm(vm) {
}

Intro::~Intro() {
}

bool Intro::handleEvent(const AgrippaEvent &evt) {
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

    case Common::EVENT_LBUTTONDOWN:
    case Common::EVENT_RBUTTONDOWN:
        return mouseEvent(evt);

    }

    return false;
}

bool Intro::mountEvent(const AgrippaEvent &evt) {
    _currentNode = getIntroNodes();
    _vm->getVideoManager()->play(_currentNode->getPath());
    
    //    Node* node = this->getIntroNodes();
    //    _video->play(node->getPath());
    
    // _video->play("xv/56003.xmv");
    // _video->play("xv/56002.xmv");
    // _video->play("xv/19668.xmv");
    // _video->play("xv/56001.xmv");
    // _video->play("xv/64421.xmv");
    // _video->play("xv/19812.xmv");
    // _video->play("nav1.nmv");
     
    return true;
}

bool Intro::unmountEvent(const AgrippaEvent &evt) {
    return true;
}

bool Intro::updateEvent(const AgrippaEvent &evt) {
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    }
    
    if (_skip || !_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->stopVideos();
        _vm->fillScreen(0);
        if (_currentNode->getId() == 56001) {
            _vm->switchEventHandler(NULL); // _vm->getMenu()
        } else {
            Node *previous = _currentNode;
            Node::NodeList nodes = _currentNode->getTarget();
            _currentNode = nodes.front();
            if (_currentNode != NULL) {
                _vm->getVideoManager()->play(_currentNode->getPath());
            }
            delete previous;
        }
    }
    
    _skip = false;
    
    // _video->pauseVideos();
    return true;
}

bool Intro::keyEvent(const AgrippaEvent &evt) {
    return true;
}

bool Intro::mouseEvent(const AgrippaEvent &evt) {
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

Node* Intro::getIntroNodes() {
    Node* N56003 = new Node(kNodeTypeVideo, 56003, "xv/56003.xmv", "Fox Interactive");
    Node* N56002 = new Node(kNodeTypeVideo, 56002, "xv/56002.xmv", "HyperBole Studios");
    Node* N19668 = new Node(kNodeTypeVideo, 19668, "xv/19668.xmv", "Warehouse Intro Sequence");
    Node* N56001 = new Node(kNodeTypeVideo, 56001, "xv/56001.xmv", "X-Files Openning Sequence");
    
    N56003->linkTarget(N56002);
    N56002->linkTarget(N19668);
    N19668->linkTarget(N56001);
    
    return N56003;
}

}

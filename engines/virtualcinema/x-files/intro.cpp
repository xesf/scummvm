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

#include "virtualcinema/core/eventHandler.h"

#include "intro.h"

namespace VirtualCinema {

Intro::Intro(AgrippaEngine *vm): _vm(vm) {
}

Intro::~Intro() {
}

VideoNode* Intro::getIntroNodes() {
    VideoNode* N56003 = new VideoNode(56003, "xv/56003.xmv", "Fox Interactive");
    VideoNode* N56002 = new VideoNode(56002, "xv/56002.xmv", "HyperBole Studios");
    VideoNode* N19668 = new VideoNode(19668, "xv/19668.xmv", "Warehouse Intro Sequence");
    VideoNode* N56001 = new VideoNode(56001, "xv/56001.xmv", "X-Files Openning Sequence");
    
    N56003->linkTarget(N56002);
    N56002->linkTarget(N19668);
    N19668->linkTarget(N56001);
    
    return N56003;
}

bool Intro::mountEvent(const VCEvent &evt) {
    _currentNode = getIntroNodes();
    _vm->getVideoManager()->play(_currentNode->getPath());

    return true;
}

bool Intro::unmountEvent(const VCEvent &evt) {
    return true;
}

bool Intro::updateEvent(const VCEvent &evt) {
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    }
    
    if (_skip || !_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->stopVideos();
        _vm->fillScreen(0);
        if (_currentNode->getId() == 56001) {
            delete _currentNode;
            _vm->switchEventHandler(_vm->getMenu());
        } else {
            VideoNode *previous = _currentNode;
            Node::NodeList nodes = _currentNode->getTarget();
            _currentNode = (VideoNode *)nodes.front();
            if (_currentNode != NULL) {
                _vm->getVideoManager()->play(_currentNode->getPath());
            }
            delete previous;
        }
        _skip = false;
    }
    
    return true;
}

bool Intro::keyEvent(const VCEvent &evt) {
    return true;
}

bool Intro::mouseEvent(const VCEvent &evt) {
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

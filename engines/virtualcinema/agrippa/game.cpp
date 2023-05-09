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
#include "nodes/decisionNode.h"

namespace VirtualCinema {

Game::Game(AgrippaEngine *vm): _vm(vm) {
}

Game::~Game() {
}

bool Game::handleEvent(const AgrippaEvent &evt) {
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

bool Game::mountEvent(const AgrippaEvent &evt) {
    VideoNode* N64421 = new VideoNode(64421, "xv/64421.xmv", "Seattle Office");
    VideoNode* N19812 = new VideoNode(19812, "xv/19812.xmv", "Willmore Entering Office");
    DecisionNode* N25683 = new DecisionNode(25683, "xn/25683.xmv", "Emotion Decision - Willmore Entering Office");
    N25683->setLooping(true);
    
    N64421->linkTarget(N19812);
    N19812->linkTarget(N25683);
    
    _currentNode = N64421;
    VideoEntryPtr video = _vm->getVideoManager()->play(_currentNode->getPath());
    video.get()->setY(80);
    
    return true;
}

bool Game::unmountEvent(const AgrippaEvent &evt) {
    return true;
}

bool Game::updateEvent(const AgrippaEvent &evt) {
    if (_vm->getVideoManager()->isVideoPlaying()) {
        _vm->getVideoManager()->updateMovies();
    }
    
    if (!_vm->getVideoManager()->isVideoPlaying()) {
        if (_currentNode->getId() != 25683) { // for testing purposes
            _vm->getVideoManager()->stopVideos();
            _vm->fillScreen(0);
            Node *previous = _currentNode;
            Node::NodeList nodes = _currentNode->getTarget();
            _currentNode = nodes.front();
            if (_currentNode != NULL) {
                VideoEntryPtr video = _vm->getVideoManager()->play(_currentNode->getPath());
                video.get()->setY(80);
            }
            delete previous;
        }
    }

    return true;
}

bool Game::keyEvent(const AgrippaEvent &evt) {
    return true;
}

bool Game::mouseEvent(const AgrippaEvent &evt) {
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

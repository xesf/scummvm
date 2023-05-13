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

#ifndef VIRTUALCINEMA_GAME_H
#define VIRTUALCINEMA_GAME_H

#include "virtualcinema/core/eventHandler.h"

#include "agrippa.h"
#include "nodes/videoNode.h"

namespace VirtualCinema {

class AgrippaEngine;

class Game : public EventHandler {
public:
    Game(AgrippaEngine *vm);
    ~Game();
    
    bool handleEvent(const VCEvent &evt);

protected:
    bool mountEvent(const VCEvent &evt);
    bool unmountEvent(const VCEvent &evt);
    bool updateEvent(const VCEvent &evt);
    bool keyEvent(const VCEvent &evt);
    bool mouseEvent(const VCEvent &evt);
    bool cursorEvent(const VCEvent &evt) { return true; };
    
private:
    AgrippaEngine *_vm;
    
    Node *_currentNode;
};

} // End of namespace VirtualCinema
 
#endif

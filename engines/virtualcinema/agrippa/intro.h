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

#ifndef VIRTUALCINEMA_INTRO_H
#define VIRTUALCINEMA_INTRO_H

#include "virtualcinema/agrippa/nodes/node.h"
#include "virtualcinema/agrippa/eventHandler.h"
#include "virtualcinema/agrippa/agrippa.h"

namespace VirtualCinema {

class Intro : public EventHandler {
public:
    Intro(AgrippaEngine *vm);
    ~Intro();
    
    bool handleEvent(const AgrippaEvent &evt);

protected:
    bool mountEvent(const AgrippaEvent &evt);
    bool unmountEvent(const AgrippaEvent &evt);
    bool updateEvent(const AgrippaEvent &evt);
    bool keyEvent(const AgrippaEvent &evt);
    bool mouseEvent(const AgrippaEvent &evt);
    bool cursorEvent(const AgrippaEvent &evt) { return true; };
    
private:
    AgrippaEngine *_vm;
    bool _skip = false;
    
    Node *_currentNode;
    Node* getIntroNodes();
};

} // End of namespace VirtualCinema
 
#endif

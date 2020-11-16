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

#ifndef DGDS_EVENTHANDLER_H
#define DGDS_EVENTHANDLER_H

#include "common/func.h"
#include "common/events.h"

namespace Dgds {

enum CastawayEventType {
    EVENT_CASTAWAY_NONE     = 1000,
    
    EVENT_CASTAWAY_MOUNT    = 1001,
    EVENT_CASTAWAY_UPDATE   = 1002,
    EVENT_CASTAWAY_UNMOUNT  = 1003,

    EVENT_CASTAWAY_ACTIVATE = 1999
};

struct CastawayEvent : public Common::Event {
    CastawayEvent() : Event() {
        param1 = 0;
        param2 = 0;
    }

    CastawayEvent(CastawayEventType msgType, int32 p1 = 0, int32 p2 = 0) : Event() {
        type = (Common::EventType)msgType;
        param1 = p1;
        param2 = p2;
    }

    int32 param1;
    int32 param2;
};

class EventHandler {
public:
    virtual ~EventHandler() {}

    virtual bool handleEvent(const CastawayEvent &ev) = 0;
    
    virtual bool mountEvent(const CastawayEvent &evt) = 0;
    virtual bool unmountEvent(const CastawayEvent &evt) = 0;
    
    virtual bool updateEvent(const CastawayEvent &evt) = 0;
    virtual bool keyEvent(const CastawayEvent &evt) = 0;
    virtual bool mouseEvent(const CastawayEvent &evt) = 0;
};

} // End of namespace Dgds

#endif // DGDS_EVENTHANDLER_H

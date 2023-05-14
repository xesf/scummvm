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

#ifndef VIRTUALCINEMA_SCENE_H
#define VIRTUALCINEMA_SCENE_H

#include "virtualcinema/core/vcengine.h"
#include "virtualcinema/core/eventHandler.h"
#include "virtualcinema/core/video.h"


namespace VirtualCinema {

class VCEngine;

class Scene : public EventHandler {
public:
    Scene();
    ~Scene();
    
    bool handleEvent(const VCEvent &evt);

protected:
    virtual bool mountEvent(const VCEvent &evt);
    virtual bool unmountEvent(const VCEvent &evt);
    virtual bool updateEvent(const VCEvent &evt);
    virtual bool keyEvent(const VCEvent &evt);
    virtual bool mouseEvent(const VCEvent &evt);
    virtual bool cursorEvent(const VCEvent &evt) { return true; };
};

} // End of namespace VirtualCinema
 
#endif

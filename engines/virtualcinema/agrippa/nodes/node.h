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

#ifndef NODE_H
#define NODE_H
 
#include "common/random.h"
#include "engines/engine.h"
#include "gui/debugger.h"

namespace VirtualCinema {

enum {
    kNodeTypeNone = 1 << 0,
    kNodeTypeVideo = 1 << 1,
    kNodeTypeDecision = 1 << 2,
    kNodeTypeNavigation = 1 << 3,
};

class Node {
public:
    Node(int type, int id, Common::String path, Common::String desc);
    ~Node() {};
    
    int getId() { return _id; };
    int getType() { return _type; };
    const Common::String& getPath() { return _path; };
    const Common::String& getDesc() { return _desc; };
    
    typedef Common::List<Node*> NodeList;
    NodeList getSource() { return _source; };
    NodeList getTarget() { return _target; };
    
    void linkSource(Node* source) { _source.push_back(source); };
    void linkTarget(Node* target) { _target.push_back(target); };
     
protected:
    int _id;
    int _type;
    Common::String _path;
    Common::String _desc;
    
    NodeList _source;
    NodeList _target;

};

} // End of namespace VirtualCinema
 
#endif

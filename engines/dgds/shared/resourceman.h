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

#ifndef DGDS_RESOURCE_MANAGER_H
#define DGDS_RESOURCE_MANAGER_H

#include "common/file.h"
#include "common/hashmap.h"
#include "common/platform.h"

namespace Common {
    class SeekableReadStream;
}

namespace Dgds {

struct ResourceEntry {
	Common::String name;
	Common::String type;
	uint32 size;
	uint32 offset;
	uint32 compressedSize;
	byte* buffer;
};

typedef Common::HashMap<Common::String, ResourceEntry> ResourceList;

class ResourceManager {
public:
	ResourceManager();
	virtual ~ResourceManager();

	void load(Common::String name);

	// Common::SeekableReadStream *getResource(Common::String name);
	ResourceEntry getResourceInfo(Common::String name);
	ResourceList _resources;
};

} // End of namespace Dgds

#endif // DGDS_RESOURCE_MANAGER_H

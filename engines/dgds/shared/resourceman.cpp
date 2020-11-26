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

#include "resourceman.h"
#include "resources/resource.h"

#include "common/debug.h"
#include "common/file.h"
#include "common/memstream.h"
#include "common/platform.h"
#include "common/str.h"
#include "common/stream.h"
#include "common/substream.h"

namespace Dgds {

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
}

void ResourceManager::load(Common::String name) {
    if (!Common::File::exists(name)) {
        return;
    }
    
    int32 FILENAME_LENGTH = 13;
	Common::File mapFile;
    mapFile.open(name);
	mapFile.skip(4);
	int32 numResources = mapFile.readUint16LE();

	for (int32 i = 0; i < numResources; i++) {
		Common::String resourceName;
		for (int32 j = 0; j < FILENAME_LENGTH; j++) {
			resourceName += mapFile.readByte();
        }
		resourceName.toLowercase();

		Common::File resourceFile;
        resourceFile.open(resourceName);

		int32 numEntries = mapFile.readUint16LE();
		debug("Resource %s has %d entries", resourceName.c_str(), numEntries);

		for (int j = 0; j < numEntries; j++) {
			ResourceEntry res;
			res.size = mapFile.readUint32LE();
			res.offset = mapFile.readUint32LE();

			resourceFile.seek(res.offset, SEEK_SET);
			res.offset += FILENAME_LENGTH + 1 + 4;
            
            char *name = (char *)malloc(sizeof(char) * FILENAME_LENGTH);
            resourceFile.read(name, FILENAME_LENGTH);

            res.name = Common::String((const char *)name);
            res.type = res.name.substr(res.name.find(".") + 1, 3);
			res.compressedSize = resourceFile.readUint32LE();
            res.buffer = (byte *)malloc(sizeof(byte) * res.compressedSize);
            resourceFile.read(res.buffer, res.compressedSize);

			_resources[res.name] = res;
            // debug("Entry %s %s", res.name.c_str(), res.type.c_str());
		}
        resourceFile.close();
	}

	mapFile.close();
    return;
}

}

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

#include "bladerunner/archive.h"

#include "common/debug.h"

namespace BladeRunner {

MIXArchive::MIXArchive() {
}

MIXArchive::~MIXArchive() {
	if (_fd.isOpen())
		debug("~MIXArchive: fd not closed: %s", _fd.getName());
}

bool MIXArchive::open(const Common::String &filename) {
	if (!_fd.open(filename)) {
		debug("MIXArchive::open(): Could not open %s", filename.c_str());
		return false;
	}

	_isTLK = filename.hasSuffix(".TLK");

	_entry_count = _fd.readUint16LE();
	_size        = _fd.readUint32LE();

	_entries.resize(_entry_count);
	for (uint16 i = 0; i != _entry_count; ++i) {
		_entries[i].id     = _fd.readSint32LE();
		_entries[i].offset = _fd.readUint32LE();
		_entries[i].length = _fd.readUint32LE();

		if (false)
			debug("%08x %-12d %-12d", _entries[i].id, _entries[i].offset, _entries[i].length);

		// Verify that the entries are sorted by id. Note that id is signed.
		if (i > 0)
			assert(_entries[i].id > _entries[i - 1].id);
	}

	if (_fd.err()) {
		error("MIXArchive::open(): Error reading entries in %s", filename.c_str());
		_fd.close();
		return false;
	}

	// debug("MIXArchive::open: Opened archive %s", filename.c_str());

	return true;
}

void MIXArchive::close() {
	return _fd.close();
}

bool MIXArchive::isOpen() const {
	return _fd.isOpen();
}

#define ROL(n) ((n << 1) | ((n >> 31) & 1))

int32 mix_id(const Common::String &name) {
	char buffer[12] = { 0 };

	for (uint i = 0; i != name.size() && i < 12u; ++i)
		buffer[i] = (char)toupper(name[i]);

	uint32 id = 0;
	for (int i = 0; i < 12 && buffer[i]; i += 4)
	{
		uint32 t = (uint32)buffer[i + 3] << 24
		         | (uint32)buffer[i + 2] << 16
		         | (uint32)buffer[i + 1] <<  8
		         | (uint32)buffer[i + 0];

		id = ROL(id) + t;
	}

	return reinterpret_cast<int32&>(id);
}

static
int32 tlk_id(const Common::String &name) {
	char buffer[12] = { 0 };

	for (uint i = 0; i != name.size() && i < 12u; ++i)
		buffer[i] = (char)toupper(name[i]);

	int actor_id  =   10 * (buffer[0] - '0') +
	                       (buffer[1] - '0');

	int speech_id = 1000 * (buffer[3] - '0') +
	                 100 * (buffer[4] - '0') +
	                  10 * (buffer[5] - '0') +
	                       (buffer[6] - '0');

	return 10000 * actor_id + speech_id;
}

uint32 MIXArchive::indexForId(int32 id) const {
	uint32 lo = 0, hi = _entry_count;

	while (lo < hi) {
		uint32 mid = lo + (hi - lo) / 2;

		if (id > _entries[mid].id)
			lo = mid + 1;
		else if (id < _entries[mid].id)
			hi = mid;
		else
			return mid;
	}
	return _entry_count;
}

Common::SeekableReadStream *MIXArchive::createReadStreamForMember(const Common::String &name) {
	int32 id;

	if (_isTLK)
		id = tlk_id(name);
	else
		id = mix_id(name);

	uint32 i = indexForId(id);

	if (i == _entry_count)
		return NULL;

	uint32 start = _entries[i].offset + 6 + 12 * _entry_count;
	uint32 end   = _entries[i].length + start;

	return new Common::SafeSeekableSubReadStream(&_fd, start, end, DisposeAfterUse::NO);
}

} // End of namespace BladeRunner

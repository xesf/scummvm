/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1999-2000 Revolution Software Ltd.
 * This code is based on source code created by Revolution Software,
 * used with permission.
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

namespace ICB {

extern uint32 fileGetZipLength(const char *inFn);
uint32 fileGetZipLength2(Common::SeekableReadStream *fileStream);

// There are now two memUncompress's
// One takes a FILE * pointer and a place to unzip to
// The second takes a url, opens it, and calls the first

uint memUncompress(unsigned char *outMem, const char *inFn);
unsigned int memUncompress(unsigned char *outMem, const char *inFn, Common::SeekableReadStream *fileStream);

} // End of namespace ICB

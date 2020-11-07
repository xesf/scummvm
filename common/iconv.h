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

#ifndef COMMON_ICONV_H
#define COMMON_ICONV_H

#include "common/scummsys.h"

#ifdef USE_ICONV

namespace Common {

class String;
class U32String;

enum IconvEncoding {
	/** Windows codepage 1250 (Eastern European, Latin alphabet) */
	kEncodingCP1250,

	/** Windows codepage 1251 (Eastern European, Cyrillic alphabet) */
	kEncodingCP1251,

	/** Windows codepage 1252 (Western European, Latin alphabet) */
	kEncodingCP1252,

	/** Windows codepage 1255 (Hebrew) */
	kEncodingCP1255,

	/** Windows codepage 932 (Japanese, extended Shift-JIS) */
	kEncodingCP932,

	/** Macintosh Central European (Eastern European, Latin alphabet) */
	kEncodingMacCentralEurope
};

U32String convertToU32String(IconvEncoding fromEncoding, const String &string);

} // End of namespace Common

#endif // USE_ICONV

#endif // COMMON_ICONV_H

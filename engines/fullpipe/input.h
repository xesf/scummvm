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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef FULLPIPE_INPUT_H
#define FULLPIPE_INPUT_H

namespace Fullpipe {

void setInputDisabled(bool state);

class CInputControllerItemArray : public CObArray {
};

class CInputController {
	//CObject obj;
	int _flag;
	int _flags;
	int _cursorHandle;
	int _hCursor;
	int _field_14;
	int _cursorId;
	int _cursorIndex;
	CInputControllerItemArray _cursorsArray;
	Common::Rect _cursorBounds;
	int _cursorItemPicture;

 public:
	CInputController();
	void setInputDisabled(bool state);
};

} // End of namespace Fullpipe

#endif /* FULLPIPE_INPUT_H */

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

#include "engines/icb/gfx/psx_pcdefines.h"
#include "engines/icb/common/px_common.h"
#include "engines/icb/common/px_bones.h"

namespace ICB {

void BoneDeformation::UpdateBoneValue(short &v, short t) {
	if (v < t) {
		v = (short)(v + boneSpeed);
		if (v > t)
			v = t;
	} else if (v > t) {
		v = (short)(v - boneSpeed);
		if (v < t)
			v = t;
	}
}

void BoneDeformation::Target0() { boneTarget.vx = boneTarget.vy = boneTarget.vz = 0; }

void BoneDeformation::Update() {
	UpdateBoneValue(boneValue.vx, boneTarget.vx);
	UpdateBoneValue(boneValue.vy, boneTarget.vy);
	UpdateBoneValue(boneValue.vz, boneTarget.vz);
}

} // End of namespace ICB

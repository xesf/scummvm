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

#ifndef ULTIMA_ULTIMA1_GAME_H
#define ULTIMA_ULTIMA1_GAME_H

#include "ultima/shared/early/game.h"
#include "ultima/shared/gfx/visual_container.h"

namespace Ultima {
namespace Ultima1 {

enum VideoMode {
	VIDEOMODE_EGA = 0, VIDEOMODE_VGA = 1
};

class GameResources;

class Ultima1Game : public Shared::Game {
	DECLARE_MESSAGE_MAP;
public:
	GameResources *_res;
	Shared::Gfx::VisualContainer *_gameView;
	Shared::Gfx::VisualContainer *_titleView;
public:
	CLASSDEF;
	Ultima1Game();
	virtual ~Ultima1Game();

	/**
	 * Returns true if the current video mode is VGA
	 */
	virtual bool isVGA() const { return _videoMode == VIDEOMODE_VGA; }

	/**
	 * Called when the game starts
	 */
	void starting();
};

} // End of namespace Ultima1
} // End of namespace Ultima

#endif

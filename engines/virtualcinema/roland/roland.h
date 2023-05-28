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

#ifndef VIRTUALCINEMA_ROLAND_H
#define VIRTUALCINEMA_ROLAND_H
 
#include "common/random.h"
#include "engines/engine.h"
#include "gui/debugger.h"
#include "graphics/font.h"

#include "virtualcinema/core/vcengine.h"

namespace VirtualCinema {

class RolandEngine : public VCEngine {
public:
    /*
    Chapters Indexes: 7
        Seige of Paris
        Beware the Forest Green
        Black is the Kight
        A Chapel, Small and Dear
        La Bella Luna
        The Tide Turns
        Epilogue
    */
    uint16 _chapterNumber = 1;
    uint16 _pageNumber = 1;
    /*
    Characters Indexes: 5
        Angelica: 1
        Charlemagne: 2
        Durendal: 3
        Roland: 4
        Main Leaf: 5
    */
    uint16 _characterIndex = 5;
    uint16 _selectedMenu = 0;

public:
    RolandEngine(OSystem *syst);
    ~RolandEngine();

    const Graphics::Font* getFont() { return _font; }

private:
    const Graphics::Font *_font;
};

} // End of namespace VirtualCinema
 
#endif

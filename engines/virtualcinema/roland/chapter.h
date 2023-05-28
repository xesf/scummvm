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

#ifndef VIRTUALCINEMA_CHAPTER_H
#define VIRTUALCINEMA_CHAPTER_H

#include "image/bmp.h"

#include "virtualcinema/core/scene.h"
#include "roland.h"

namespace VirtualCinema {

class RolandEngine;

class Chapter : public Scene {
public:
    Chapter(RolandEngine *vm);
    ~Chapter();

protected:
    bool mountEvent(const VCEvent &evt) override;
    bool unmountEvent(const VCEvent &evt) override;
    bool updateEvent(const VCEvent &evt) override;
    bool keyEvent(const VCEvent &evt) override;
    bool mouseEvent(const VCEvent &evt) override;
    
private:
    RolandEngine *_vm;
    bool _skip = false;

    ImageEntryPtr _page;

    uint16 _prevPageNumber = 1;
    uint16 _prevCharacterIndex = 5;
    uint16 _maxPageNumber = 20;

    char getCharacterIndexLetter();
    char getPageLetter();
    void switchPage();

    // Debug
    Common::Point _mousePos;
    Common::Point _mousePosStart;
    Common::Point _mousePosEnd;
    bool _mouseStartSet = false;
    bool _mouseEndSet = false;

    // Common Hotspots
    const Common::Rect _cardHotspot[4] = {
        Common::Rect(68, 54, 110, 138),  // Card 1
        Common::Rect(68, 150, 110, 238), // Card 2
        Common::Rect(68, 246, 110, 330), // Card 3
        Common::Rect(68, 340, 110, 424), // Card 4
    };
    const Common::Rect _menuHotspot[4] = {
        Common::Rect(118, 58, 144, 92), // Help
        Common::Rect(150, 58, 180, 92), // Bookmarks
        Common::Rect(188, 58, 216, 92), // Music
        Common::Rect(222, 58, 254, 92), // Map
    };
    const Common::Rect _chapterHotspot[3] = {
        Common::Rect(264, 58, 305, 92), // Sun
        Common::Rect(318, 58, 440, 92), // Chapter
        Common::Rect(450, 58, 488, 92), // Moon
    };
    const Common::Rect _pageHotspot[3] = {
        Common::Rect(494, 58, 516, 92), // Left
        Common::Rect(520, 59, 542, 92), // Home
        Common::Rect(548, 58, 570, 92), // Right
    };
};

} // End of namespace VirtualCinema
 
#endif

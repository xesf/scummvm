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

#ifndef VIRTUALCINEMA_MENU_H
#define VIRTUALCINEMA_MENU_H

#include "eventHandler.h"
#include "agrippa.h"
#include "video.h"

namespace VirtualCinema {

class Menu : public EventHandler {
public:
    Menu(AgrippaEngine *vm);
    ~Menu();
    
    bool handleEvent(const AgrippaEvent &evt);

protected:
    bool mountEvent(const AgrippaEvent &evt);
    bool unmountEvent(const AgrippaEvent &evt);
    bool updateEvent(const AgrippaEvent &evt);
    bool keyEvent(const AgrippaEvent &evt);
    bool mouseEvent(const AgrippaEvent &evt);
    bool cursorEvent(const AgrippaEvent &evt) { return true; };
    
private:
    AgrippaEngine *_vm;
    
    VideoEntryPtr _intro;
    VideoEntryPtr _title;
    VideoEntryPtr _background;
    VideoEntryPtr _menuItems;
    
    bool _titlePlaying = false;
    Common::Rect _titleRect;
    
    int _selectedMenuItem = -1;
    
    void mountMenu();
    void mountMenuTitle();
    void mountMenuItems(bool reloaded);
    
    enum {
        kMenuItemNew      = 0,
        kMenuItemLoad     = 1,
        kMenuItemSave     = 2,
        kMenuItemPrevious = 3,
        kMenuItemOptions  = 4,
        kMenuItemHelp     = 5,
        kMenuItemQuit     = 6,
    };
    
    const Common::Rect _menuItemsRects[7] = {
        Common::Rect( 472, 30,  640, 70),
        Common::Rect( 472, 70,  640, 120),
        Common::Rect( 472, 120, 640, 170),
        Common::Rect( 472, 170, 640, 220),
        Common::Rect( 472, 220, 640, 270),
        Common::Rect( 472, 270, 640, 320),
        Common::Rect( 472, 320, 640, 370),
        // Common::Rect( 472, 370, 640, 420),
    };
    
    const Audio::Timestamp _menuItemsBoundStart[7] = {
        Audio::Timestamp(5000,  600),
        Audio::Timestamp(5900,  600),
        Audio::Timestamp(6800,  600),
        Audio::Timestamp(7700,  600),
        Audio::Timestamp(8600,  600),
        Audio::Timestamp(9500, 600),
        Audio::Timestamp(10400, 600),
    };
    const Audio::Timestamp _menuItemsBoundEnd[7] = {
        Audio::Timestamp(5900,  600),
        Audio::Timestamp(6800,  600),
        Audio::Timestamp(7700,  600),
        Audio::Timestamp(8600,  600),
        Audio::Timestamp(9500, 600),
        Audio::Timestamp(10400, 600),
        Audio::Timestamp(11500, 600),
    };
};

} // End of namespace VirtualCinema
 
#endif

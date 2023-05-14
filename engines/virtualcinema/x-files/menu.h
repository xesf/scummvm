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

#include "virtualcinema/core/scene.h"
#include "virtualcinema/core/video.h"

#include "agrippa.h"

namespace VirtualCinema {

class AgrippaEngine;

class Menu : public Scene {
public:
    Menu(AgrippaEngine *vm);
    ~Menu();

protected:
    bool mountEvent(const VCEvent &evt) override;
    bool unmountEvent(const VCEvent &evt) override;
    bool updateEvent(const VCEvent &evt) override;
    bool mouseEvent(const VCEvent &evt) override;
    
private:
    AgrippaEngine *_vm;

    VideoEntryPtr _intro;
    VideoEntryPtr _title;
    VideoEntryPtr _background;
    VideoEntryPtr _menuItems;
    
    // bool _titlePlaying = false;
    Common::Rect _titleRect;
    
    int _selectedMenuItem = -1;
    bool _canInteract = false;
    bool _menuMounted = false;
    
    void mountMenu();
    void mountMenuTitle();
    void mountMenuItems();
    
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
        Common::Rect( 472, 70,  640, 120),
        Common::Rect( 472, 120, 640, 170),
        Common::Rect( 472, 170, 640, 220),
        Common::Rect( 472, 220, 640, 270),
        Common::Rect( 472, 270, 640, 320),
        Common::Rect( 472, 320, 640, 370),
        Common::Rect( 472, 370, 640, 420),
    };
    
    const Audio::Timestamp _menuItemsBoundStart[7] = {
        Audio::Timestamp(5900,  600),
        Audio::Timestamp(6800,  600),
        Audio::Timestamp(7700,  600),
        Audio::Timestamp(8600,  600),
        Audio::Timestamp(9500, 600),
        Audio::Timestamp(10400, 600),
        Audio::Timestamp(11500, 600),
    };
    const Audio::Timestamp _menuItemsBoundEnd[7] = {
        Audio::Timestamp(6800,  600),
        Audio::Timestamp(7700,  600),
        Audio::Timestamp(8600,  600),
        Audio::Timestamp(9500, 600),
        Audio::Timestamp(10400, 600),
        Audio::Timestamp(11500, 600),
        Audio::Timestamp(12400, 600),
    };
};

} // End of namespace VirtualCinema
 
#endif

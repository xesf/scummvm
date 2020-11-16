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

#ifndef DGDS_CASTAWAY_H
#define DGDS_CASTAWAY_H
 
#include "common/random.h"
#include "engines/engine.h"
#include "gui/debugger.h"


#include "console.h"
#include "eventHandler.h"
#include "game.h"
 
namespace Dgds {
 
class Console;
class Game;

enum {
    kDebugLevelMain = 1 << 0,
    kDebugLevelResources = 1 << 1,
};

class CastawayEngine : public Engine {
public:
    CastawayEngine(OSystem *syst);
    ~CastawayEngine();

    virtual Common::Error run();
    virtual Common::Error handleEvents();
    
    void switchEventHandler(EventHandler *handler);
    void notifyEvent(CastawayEventType type, int32 param1, int32 param2);
    
    Game* getGame() { return _game; };
    
    void fillScreen(uint32 col);
 
private:
    Common::RandomSource *_rnd;
    Console *_console;

    EventHandler *_handler;

    Game *_game;
};

} // End of namespace Dgds
 
#endif

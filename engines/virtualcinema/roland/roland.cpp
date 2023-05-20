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

#include "common/scummsys.h"
 
#include "common/config-manager.h"
#include "common/debug.h"
#include "common/debug-channels.h"
#include "common/error.h"
#include "gui/EventRecorder.h"
#include "common/file.h"
#include "common/fs.h"
 
#include "graphics/cursorman.h"
#include "engines/util.h"

#include "virtualcinema/core/vcengine.h"
#include "virtualcinema/core/eventHandler.h"
#include "virtualcinema/core/console.h"
#include "virtualcinema/core/video.h"

#include "roland.h"

// #include "intro.h"

// #include "nodes/node.h"
 
namespace VirtualCinema {
 
RolandEngine::RolandEngine(OSystem *syst)
    : VCEngine(syst) {

    const Common::FSNode gameDataDir(ConfMan.get("path"));
    SearchMan.addSubDirectoryMatching(gameDataDir, "hyper");
    SearchMan.addSubDirectoryMatching(gameDataDir, "menus");
    SearchMan.addSubDirectoryMatching(gameDataDir, "qt");
    SearchMan.addSubDirectoryMatching(gameDataDir, "screens");

    // Common debug channels
    // DebugMan.addDebugChannel(kDebugLevelMain, "Main", "Generic debug level");
    // DebugMan.addDebugChannel(kDebugLevelResources, "Resources", "Resources debugging");

    _intro = new RIntro(this);
    // _menu = new Menu(this);
    // _game = new Game(this);

    _handler = _intro;

    debug("RolandEngine::RolandEngine");
}
 
RolandEngine::~RolandEngine() {
    debug("RolandEngine::~RolandEngine");
    _handler = NULL;

    // delete _game;
    // delete _menu;
    delete _intro;
}
 
} // End of namespace VirtualCinema

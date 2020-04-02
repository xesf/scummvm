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
 
#include "engines/util.h"

#include "dgds/console.h"
#include "dgds/dgds.h"
 
namespace Dgds {
 
DgdsEngine::DgdsEngine(OSystem *syst)
 : Engine(syst), _console(nullptr) {
    // const Common::FSNode gameDataDir(ConfMan.get("path"));
    // SearchMan.addSubDirectoryMatching(gameDataDir, "data");
 
    // Common debug channels
    DebugMan.addDebugChannel(kDebugLevelMain, "Main", "Generic debug level");
    DebugMan.addDebugChannel(kDebugLevelResources, "Resources", "Resources debugging");
    DebugMan.addDebugChannel(kDebugLevelBackgroundImages, "BackgroundImages", "Background images debugging");
    DebugMan.addDebugChannel(kDebugLevelBitmapImages, "BitmapImages", "Bitmap images debugging");
    DebugMan.addDebugChannel(kDebugLevelSceneScripts, "SceneScripts", "Scene scripts debugging");
    DebugMan.addDebugChannel(kDebugLevelScenes, "Scenes", "Scenes animation debugging");

    _rnd = new Common::RandomSource("Dgds");
 
    debug("DgdsEngine::DgdsEngine");
}
 
DgdsEngine::~DgdsEngine() {
    debug("DgdsEngine::~DgdsEngine");

    delete _rnd;

    DebugMan.clearAllDebugChannels();
}
 
Common::Error DgdsEngine::run() {
    // Initialize graphics using following:
    initGraphics(640, 480);
 
    _console = new Console(this);
 
    debug("DgdsEngine::init");
    
    debugC(1, kDebugLevelMain, "Example debug call");
 
    return Common::kNoError;
}
 
} // End of namespace Dgds

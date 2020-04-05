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

#include "console.h"
#include "video.h"
#include "agrippa.h"

#include "nodes/node.h"
 
namespace VirtualCinema {
 
AgrippaEngine::AgrippaEngine(OSystem *syst)
 : Engine(syst), _console(nullptr) {
     _rnd = new Common::RandomSource("AgrippaEngine");
     
     const Common::FSNode gameDataDir(ConfMan.get("path"));
     SearchMan.addSubDirectoryMatching(gameDataDir, "xg");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xn");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xs");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xt");
     SearchMan.addSubDirectoryMatching(gameDataDir, "xv");
 
    // Common debug channels
    DebugMan.addDebugChannel(kDebugLevelMain, "Main", "Generic debug level");
    DebugMan.addDebugChannel(kDebugLevelResources, "Resources", "Resources debugging");
 
    debug("AgrippaEngine::AgrippaEngine");
}
 
AgrippaEngine::~AgrippaEngine() {
    debug("AgrippaEngine::~AgrippaEngine");
    delete _rnd;
    DebugMan.clearAllDebugChannels();
}

Node* AgrippaEngine::getIntroNodes() {
    Node* N56003 = new Node(kNodeTypeVideo, 56003, "xv/56003.xmv", "Fox Interactive");
    Node* N56002 = new Node(kNodeTypeVideo, 56002, "xv/56002.xmv", "HyperBole Studios");
    Node* N19668 = new Node(kNodeTypeVideo, 56002, "xv/19668.xmv", "Warehouse Intro Sequence");
    Node* N56001 = new Node(kNodeTypeVideo, 56001, "xv/19668.xmv", "X-Files Openning Sequence");
    
    N56003->linkTarget(N56002);
    N56002->linkTarget(N19668);
    N19668->linkTarget(N56001);
    
    return N56003;
}
 
Common::Error AgrippaEngine::run() {
    Graphics::PixelFormat pixelFormat = Graphics::PixelFormat(4, 8, 8, 8, 8, 8, 16, 24, 0); // 24bpp

    initGraphics(640, 480, &pixelFormat);
 
    _console = new Console(this);
    _video = new VideoManager(this);
    
    Node* node = this->getIntroNodes();
    _video->play(node->getPath());
    
    // _video->play("xv/56003.xmv");
    // _video->play("xv/56002.xmv");
    // _video->play("xv/19668.xmv");
    // _video->play("xv/56001.xmv");
    // _video->play("xv/64421.xmv");
    // _video->play("xv/19812.xmv");
    // _video->play("nav1.nmv");
 
    debug("AgrippaEngine::init");
    
    debugC(1, kDebugLevelMain, "Example debug call");
 
    while (!shouldQuit()) {
        processFrame();
        // _video->pauseVideos();
    }

    return Common::kNoError;
}

Common::Error AgrippaEngine::processFrame() {
    _video->updateMovies();

    Common::Event event;
    while (_system->getEventManager()->pollEvent(event)) {
        // TODO check events
        // ESC or Mouse Click for skipping movies
    }

    _system->updateScreen();

    // cut down on CPU usage
    _system->delayMillis(10);

    return Common::kNoError;
}
 
} // End of namespace VirtualCinema

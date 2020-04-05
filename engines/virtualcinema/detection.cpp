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

#include "virtualcinema/detection.h"
#include "base/plugins.h"
#include "common/system.h"
#include "common/config-manager.h"
#include "common/savefile.h"
#include "common/str-array.h"
#include "common/memstream.h"
#include "common/translation.h"

#include "virtualcinema/agrippa/agrippa.h"

namespace VirtualCinema {

class AgrippaEngine;

static const PlainGameDescriptor VIRTUALCINEMA_GAMES[] = {
    { "agrippa", "The X-Files Game" },
    { 0, 0 }
};

} // End of namespace Dgds

#include "virtualcinema/detection_tables.h"

VirtualCinemaMetaEngine::VirtualCinemaMetaEngine() : AdvancedMetaEngine(VirtualCinema::GAME_DESCRIPTIONS,
            sizeof(VirtualCinema::VirtualCinemaGameDescription), VirtualCinema::VIRTUALCINEMA_GAMES) {
    static const char *const DIRECTORY_GLOBS[2] = { "xv", 0 };
    _maxScanDepth = 2;
    _directoryGlobs = DIRECTORY_GLOBS;
}

bool VirtualCinemaMetaEngine::createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const {
    const VirtualCinema::VirtualCinemaGameDescription *gd = (const VirtualCinema::VirtualCinemaGameDescription *)desc;
    if (gd) {
        switch (gd->gameId) {
        case VirtualCinema::GAME_AGRIPPA:
            *engine = new VirtualCinema::AgrippaEngine(syst);
            break;
        default:
            error("Game not implemented");
            break;
        }
    }
    return gd != 0;
}

int VirtualCinemaMetaEngine::getMaximumSaveSlot() const {
    return MAX_SAVES;
}

const char *VirtualCinemaMetaEngine::getSavegamePattern(const char *target) const {
    static char buffer[200];
    snprintf(buffer, 200, "%s.###", target == nullptr ? getEngineId() : target);
    return buffer;
}

const char *VirtualCinemaMetaEngine::getSavegameFile(int saveGameIdx, const char *target) const {
    static char buffer[200];
    snprintf(buffer, 200, "%s.%.3d", target == nullptr ? getEngineId() : target, saveGameIdx);
    return buffer;
}

SaveStateList VirtualCinemaMetaEngine::listSaves(const char *target) const {
    SaveStateList saveList = AdvancedMetaEngine::listSaves(target);
    // TODO
    return saveList;
}

Common::KeymapArray VirtualCinemaMetaEngine::initKeymaps(const char *target) const {
    Common::String gameId = getGameId(target);
    // TODO
    return Common::KeymapArray();
}

Common::String VirtualCinemaMetaEngine::getGameId(const char *target) {
    // Store a copy of the active domain
    Common::String currDomain = ConfMan.getActiveDomainName();

    // Switch to the given target domain and get it's game Id
    ConfMan.setActiveDomain(target);
    Common::String gameId = ConfMan.get("gameid");

    // Switch back to the original domain and return the game Id
    ConfMan.setActiveDomain(currDomain);
    return gameId;
}

#if PLUGIN_ENABLED_DYNAMIC(VIRTUALCINEMA)
REGISTER_PLUGIN_DYNAMIC(VIRTUALCINEMA, PLUGIN_TYPE_ENGINE, VirtualCinemaMetaEngine);
#else
REGISTER_PLUGIN_STATIC(VIRTUALCINEMA, PLUGIN_TYPE_ENGINE, VirtualCinemaMetaEngine);
#endif

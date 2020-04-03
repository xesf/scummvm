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

#include "agrippa/detection.h"
#include "base/plugins.h"
#include "common/system.h"
#include "common/config-manager.h"
#include "common/savefile.h"
#include "common/str-array.h"
#include "common/memstream.h"
#include "common/translation.h"

#include "agrippa/agrippa.h"

namespace Agrippa {

class AgrippaEngine;

static const PlainGameDescriptor AGRIPPA_GAMES[] = {
    { "agrippa", "The X-Files Game" },
    { 0, 0 }
};

} // End of namespace Dgds

#include "agrippa/detection_tables.h"

AgrippaMetaEngine::AgrippaMetaEngine() : AdvancedMetaEngine(Agrippa::GAME_DESCRIPTIONS,
            sizeof(Agrippa::AgrippaGameDescription), Agrippa::AGRIPPA_GAMES) {
    static const char *const DIRECTORY_GLOBS[2] = { "xv", 0 };
    _maxScanDepth = 2;
    _directoryGlobs = DIRECTORY_GLOBS;
}

bool AgrippaMetaEngine::createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const {
    const Agrippa::AgrippaGameDescription *gd = (const Agrippa::AgrippaGameDescription *)desc;
    *engine = new Agrippa::AgrippaEngine(syst);
    return gd != 0;
}

int AgrippaMetaEngine::getMaximumSaveSlot() const {
    return MAX_SAVES;
}

const char *AgrippaMetaEngine::getSavegamePattern(const char *target) const {
    static char buffer[200];
    snprintf(buffer, 200, "%s.###", target == nullptr ? getEngineId() : target);
    return buffer;
}

const char *AgrippaMetaEngine::getSavegameFile(int saveGameIdx, const char *target) const {
    static char buffer[200];
    snprintf(buffer, 200, "%s.%.3d", target == nullptr ? getEngineId() : target, saveGameIdx);
    return buffer;
}

SaveStateList AgrippaMetaEngine::listSaves(const char *target) const {
    SaveStateList saveList = AdvancedMetaEngine::listSaves(target);
    // TODO
    return saveList;
}

Common::KeymapArray AgrippaMetaEngine::initKeymaps(const char *target) const {
    Common::String gameId = getGameId(target);
    // TODO
    return Common::KeymapArray();
}

Common::String AgrippaMetaEngine::getGameId(const char *target) {
    // Store a copy of the active domain
    Common::String currDomain = ConfMan.getActiveDomainName();

    // Switch to the given target domain and get it's game Id
    ConfMan.setActiveDomain(target);
    Common::String gameId = ConfMan.get("gameid");

    // Switch back to the original domain and return the game Id
    ConfMan.setActiveDomain(currDomain);
    return gameId;
}

#if PLUGIN_ENABLED_DYNAMIC(AGRIPPA)
REGISTER_PLUGIN_DYNAMIC(AGRIPPA, PLUGIN_TYPE_ENGINE, AgrippaMetaEngine);
#else
REGISTER_PLUGIN_STATIC(AGRIPPA, PLUGIN_TYPE_ENGINE, AgrippaMetaEngine);
#endif

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

#ifndef VIRTUALCINEMA_DETECTION_H
#define VIRTUALCINEMA_DETECTION_H

#include "engines/advancedDetector.h"
#include "backends/keymapper/keymapper.h"

#define MAX_SAVES 99

namespace VirtualCinema {

enum GameId {
    GAME_AGRIPPA,
    GAME_VORTEX,
    GAME_QUANTUM
};

struct VirtualCinemaGameDescription {
    ADGameDescription desc;
    GameId gameId;
};

} // End of namespace VirtualCinema

class VirtualCinemaMetaEngine : public AdvancedMetaEngine {
private:
    /**
     * Gets the game Id given a target string
     */
    static Common::String getGameId(const char *target);
public:
    VirtualCinemaMetaEngine();
    ~VirtualCinemaMetaEngine() override {}

    const char *getEngineId() const override {
        return "virtualcinema";
    }

    const char *getName() const override {
        return "VirtualCinema";
    }

    const char *getOriginalCopyright() const override {
        return "VirtualCinema is a registered trademark of HyperBole Studios, Inc.";
    }

    const char *getSavegamePattern(const char *target = nullptr) const override;
    const char *getSavegameFile(int saveGameIdx, const char *target = nullptr) const override;

    bool createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const override;
    int getMaximumSaveSlot() const override;

    /**
     * Return a list of all save states associated with the given target.
     */
    SaveStateList listSaves(const char *target) const override;

    /**
     * Initialize keymaps
     */
    Common::KeymapArray initKeymaps(const char *target) const override;
};

#endif

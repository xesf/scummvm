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

#ifndef DGDS_DETECTION
#define DGDS_DETECTION

#include "engines/advancedDetector.h"
#include "backends/keymapper/keymapper.h"

namespace Dgds {

enum GameId {
    GAME_CASTAWAY,
    GAME_DRAGON,
    GAME_HOC,
    GAME_TURBOSCI,
    GAME_WILLY
};

enum DgdsGameFeatures {
    GF_VGA_ENHANCED = 1 << 0
};

struct DgdsGameDescription {
    ADGameDescription desc;
    GameId gameId;
    uint32 features;
};

} // End of namespace Dgds

class DgdsMetaEngineDetection : public AdvancedMetaEngineDetection {
public:
    DgdsMetaEngineDetection();
    ~DgdsMetaEngineDetection() override {}

    const char *getEngineId() const override {
        return "dgds";
    }

    const char *getName() const override {
        return "Dynamix Game Development System";
    }

    const char *getOriginalCopyright() const override {
        return "Dynamix, Inc. A Sierra Company (C) 1984-2001";
    }
};

#endif

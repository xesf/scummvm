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

#include "dgds/detection.h"
#include "dgds/detection_tables.h"

#include "base/plugins.h"
#include "common/system.h"
#include "common/config-manager.h"
#include "base/plugins.h"
#include "engines/advancedDetector.h"


namespace Dgds {

static const PlainGameDescriptor DGDS_GAMES[] = {
    { "castaway", "Johnny Castaway Screen Saver" },
    { "dragon", "Rise of the Dragron" },
    { "hoc", "Heart of China" },
    { "turbosci", "Quarky & Quaysoo's Turbo Science" },
    { "willy", "The Adventures of Willy Beamish" },
    { 0, 0 }
};

} // End of namespace Dgds

DgdsMetaEngineDetection::DgdsMetaEngineDetection() : AdvancedMetaEngineDetection(Dgds::GAME_DESCRIPTIONS,
	        sizeof(Dgds::DgdsGameDescription), Dgds::DGDS_GAMES) {
}

REGISTER_PLUGIN_STATIC(DGDS_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, DgdsMetaEngineDetection);

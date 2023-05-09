/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "base/plugins.h"
#include "common/config-manager.h"
#include "common/file.h"
#include "common/md5.h"
#include "common/str-array.h"
#include "common/translation.h"
#include "common/util.h"
#include "virtualcinema/detection.h"
#include "virtualcinema/detection_tables.h"

const DebugChannelDef VirtualCinemaMetaEngineDetection::debugFlagList[] = {
	{ VirtualCinema::kDebugGraphics, "Graphics", "Graphics debug level" },
	{ VirtualCinema::kDebugPath, "Path", "Pathfinding debug level" },
	{ VirtualCinema::kDebugFilePath, "FilePath", "File path debug level" },
	{ VirtualCinema::kDebugScan, "Scan", "Scan for unrecognised games" },
	{ VirtualCinema::kDebugScript, "Script", "Enable debug script dump" },
	DEBUG_CHANNEL_END
};

VirtualCinemaMetaEngineDetection::VirtualCinemaMetaEngineDetection() : AdvancedMetaEngineDetection(VirtualCinema::gameDescriptions,
	sizeof(VirtualCinema::VirtualCinemaGameDescription), VirtualCinema::VirtualCinemaGames) {
	static const char *const DIRECTORY_GLOBS[3] = { "xv", "vob", 0 };
    _maxScanDepth = 3;
    _directoryGlobs = DIRECTORY_GLOBS;
}

REGISTER_PLUGIN_STATIC(VIRTUALCINEMA_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, VirtualCinemaMetaEngineDetection);

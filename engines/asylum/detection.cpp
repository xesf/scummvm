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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/config-manager.h"
#include "engines/advancedDetector.h"
#include "common/savefile.h"
#include "common/system.h"

#include "asylum/asylum.h"
#include "asylum/detection_table.h"

static const ADExtraGuiOptionsMap optionsList[] = {
	AD_EXTRA_GUI_OPTIONS_TERMINATOR
};

class AsylumMetaEngineDetection : public AdvancedMetaEngineDetection {
public:
	AsylumMetaEngineDetection() : AdvancedMetaEngineDetection(Asylum::gameDescriptions, sizeof(ADGameDescription), asylumGames, optionsList) {
		_md5Bytes = 0;
		_guiOptions = GUIO1(GUIO_NONE);
	}

	const char *getEngineId() const override {
		return "asylum";
	}

	virtual const char *getName() const {
		return "Sanitarium";
	}

	virtual const char *getOriginalCopyright() const {
		return "Sanitarium (c) ASC Games";
	}

	ADDetectedGame fallbackDetect(const FileMap &allFiles, const Common::FSList &fslist) const
	{
		return detectGameFilebased(allFiles, Asylum::fileBasedFallback);
	}
};

REGISTER_PLUGIN_STATIC(ASYLUM_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, AsylumMetaEngineDetection);

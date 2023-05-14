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

namespace VirtualCinema {

#define GUI_OPTIONS_ROLAND	GUIO0()
#define GUI_OPTIONS_QGATE	GUIO0()
#define GUI_OPTIONS_VORTEX	GUIO0()
#define GUI_OPTIONS_AGRIPPA	GUIO0()

const PlainGameDescriptor VirtualCinemaGames[] = {
	{ "roland", "The Madness of Roland" },
	{ "qgate", "Quantum Gate" },
	{ "vortex", "Vortex: Quantum Gate II" },
	{ "agrippa", "The X-Files Game" },
	{ 0, 0 }
};

const VirtualCinemaGameDescription gameDescriptions[] = {
	{
		// The Madness of Roland EN US
		{
			"roland",
			nullptr,
			AD_ENTRY1s("authnote.mov", "1143684de873b7c32c46b8b69579ac47", 19005022),
			Common::EN_USA,
			Common::kPlatformWindows,
			ADGF_TESTING | ADGF_CD,
			GUI_OPTIONS_ROLAND
		},
		GAME_ROLAND
	},

	{
		// The X-Files Game EN US
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19812.xmv", "ae754649c19f717621ce52e123b912e1", 4141616),
			Common::EN_USA,
			Common::kPlatformWindows,
			ADGF_TESTING | ADGF_CD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},
    
	{
		// The X-Files Game FR
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19812.xmv", "bfd1cd21da1ae2661477de2f20c41275", 4115434),
			Common::FR_FRA,
			Common::kPlatformWindows,
			ADGF_UNSTABLE | ADGF_CD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},
	
	{
		// The X-Files Game ES
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19812.xmv", "ac2cf0247a04abb385231774b8f08ef4", 4138994),
			Common::ES_ESP,
			Common::kPlatformWindows,
			ADGF_UNSTABLE | ADGF_CD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},
	
	{
		// The X-Files Game IT
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19812.xmv", "e963e14e1949a6f8ed4c4f8fe940481f", 4149005),
			Common::IT_ITA,
			Common::kPlatformWindows,
			ADGF_UNSTABLE | ADGF_CD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},
	
	{
		// The X-Files Game DE
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19812.xmv", "b008f528ddbab714a91312509ac62a28", 4132889),
			Common::DE_DEU,
			Common::kPlatformWindows,
			ADGF_UNSTABLE | ADGF_CD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},

	{
		// The X-Files Game EN DVD
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19650.vob", "f2638d898fd027b7bebb0a5b07ed265d", 13099008),
			Common::EN_USA,
			Common::kPlatformWindows,
			ADGF_UNSTABLE | ADGF_DVD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},

	{
		// The X-Files Game FR DVD
		{
			"agrippa",
			nullptr,
			AD_ENTRY1s("19650.vob", "f2638d898fd027b7bebb0a5b07ed265d", 13119488),
			Common::FR_FRA,
			Common::kPlatformWindows,
			ADGF_UNSTABLE | ADGF_DVD,
			GUI_OPTIONS_AGRIPPA
		},
		GAME_AGRIPPA
	},

	{ AD_TABLE_END_MARKER, (GameId)0 }
};

} // End of namespace VirtualCinema

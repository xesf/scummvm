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

namespace Agrippa {

static const AgrippaGameDescription GAME_DESCRIPTIONS[] = {
    {
        // The X-Files Game EN US
        {
            "agrippa",
            0,
            {
                { "19812.xmv", 0, "ae754649c19f717621ce52e123b912e1", 4141616 },
                AD_LISTEND
            },
            Common::EN_USA,
            Common::kPlatformWindows,
            ADGF_UNSTABLE,
            GUIO0()
        },
    },
    
    {
        // The X-Files Game FR
        {
            "agrippa",
            0,
            {
                { "19812.xmv", 0, "bfd1cd21da1ae2661477de2f20c41275", 4115434 },
                AD_LISTEND
            },
            Common::FR_FRA,
            Common::kPlatformWindows,
            ADGF_UNSTABLE,
            GUIO0()
        },
    },
    
    {
        // The X-Files Game ES
        {
            "agrippa",
            0,
            {
                { "19812.xmv", 0, "ac2cf0247a04abb385231774b8f08ef4", 4138994 },
                AD_LISTEND
            },
            Common::ES_ESP,
            Common::kPlatformWindows,
            ADGF_UNSTABLE,
            GUIO0()
        },
    },
    
    {
        // The X-Files Game IT
        {
            "agrippa",
            0,
            {
                { "19812.xmv", 0, "e963e14e1949a6f8ed4c4f8fe940481f", 4149005 },
                AD_LISTEND
            },
            Common::IT_ITA,
            Common::kPlatformWindows,
            ADGF_UNSTABLE,
            GUIO0()
        },
    },
    
    {
        // The X-Files Game DE
        {
            "agrippa",
            0,
            {
                { "19812.xmv", 0, "b008f528ddbab714a91312509ac62a28", 4132889 },
                AD_LISTEND
            },
            Common::DE_DEU,
            Common::kPlatformWindows,
            ADGF_UNSTABLE,
            GUIO0()
        },
    },

    { AD_TABLE_END_MARKER }
};

} // End of namespace Agrippa

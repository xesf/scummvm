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

namespace Dgds {

static const DgdsGameDescription GAME_DESCRIPTIONS[] = {
    {
        // Johnny Castaway Screen Saver
        {
            "castaway_1.01",
            0,
            {
                { "resource.map", 0, "374e6d05c5e0acd88fb5af748948c899", 1461 },
                { "resource.001", 0, "8bb6c99e9129806b5089a39d24228a36", 1175645 },
                AD_LISTEND
            },
            Common::EN_ANY,
            Common::kPlatformWindows,
            ADGF_UNSTABLE,
            GUIO0()
        },
        GAME_CASTAWAY,
        0
    },
    
    {
        // Rise of the Dragron
        {
            "dragon",
            0,
            {
                { "volume.vga", 0, "0d9590fdc883d6d99c06e7935423d180", 7823 },
                AD_LISTEND
            },
            Common::EN_ANY,
            Common::kPlatformDOS,
            ADGF_UNSTABLE,
            GUIO0()
        },
        GAME_DRAGON,
        GF_VGA_ENHANCED
    },
    
    {
        // Heart of China
        {
            "hoc",
            0,
            {
                { "volume.rfm", 0, "2da720143c1e857490daded15682df87", 9791 },
                AD_LISTEND
            },
            Common::EN_ANY,
            Common::kPlatformDOS,
            ADGF_UNSTABLE,
            GUIO0()
        },
        GAME_HOC,
        GF_VGA_ENHANCED
    },
    
    {
        // Quarky & Quaysoo's Turbo Science
        {
            "turbosci",
            0,
            {
                { "resource.map", 0, "2f6088095925b9805112925ca8c9063b", 7595 },
                AD_LISTEND
            },
            Common::EN_ANY,
            Common::kPlatformDOS,
            ADGF_UNSTABLE,
            GUIO0()
        },
        GAME_TURBOSCI,
        0
    },
    
    {
        // The Adventures of Willy Beamish
        {
            "willy",
            0,
            {
                { "volume.rfm", 0, "ba5cf24ec4b6dc044b03115a0cd5f3ff", 9896 },
                AD_LISTEND
            },
            Common::EN_ANY,
            Common::kPlatformDOS,
            ADGF_UNSTABLE,
            GUIO0()
        },
        GAME_WILLY,
        GF_VGA_ENHANCED
    },

    { AD_TABLE_END_MARKER, (GameId)0, 0 }
};

} // End of namespace Dgds

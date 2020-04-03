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
            "castaway", // v1.01
            0,
            {
                { "resource.map", 0, "374e6d05c5e0acd88fb5af748948c899", 1461 },
                { "resource.001", 0, "46acc7ab8f6d7f63838ffea5f87380e2", 1175645 },
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
                { "volume.vga", 0, "b0583c199614ed1c161a25398c5c7fba", 7823 },
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
                { "volume.rmf", 0, "677b91bc6961824f1997c187292f174e", 9791 },
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
                { "resource.map", 0, "639885b4a7c6b8e395b6ca969c94ffd9", 7595 },
                { "resource.001", 0, "67a4ebacfa73d3f54e9c489d46f3e512", 1393208 },
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
                { "volume.rmf", 0, "c2be5cd4693dfcdbe45dd0e74dd5306d", 9896 },
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

from __future__ import print_function
import sys

if len(sys.argv) < 2:
  print("Usage: python scifx_to_header.py [scifx files] > scifx.cpp")
  sys.exit(-1)

print("""
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

// NB: This file is AUTO-GENERATED by devtools/sci/scifx/scifx_to_cpp.py
// from devtools/sci/scifx/*.scifx

#include "sci/graphics/helpers.h"
#include "sci/graphics/screen.h"

namespace Sci {
""")

def Chunker(seq, size):
    return (seq[pos:pos + size] for pos in range(0, len(seq), size))

def ModToIndex(m):
  try:
    return Mods.index(m)
  except ValueError:
    Mods.append(m)
    return len(Mods)-1

def PrintMods():
  L = [ "\t{ " + ", ".join( [ "%4d" % (round(128 * (val - 1)),) for val in m ] )  + " }" for m in Mods ]
  print("static const PaletteMod paletteMods" + GID + "[] = {")
  print( ",\n".join(L) )
  print("};")

def PrintPic(pics, comments):
  print("static const PicMod picMods" + GID + "[] = {")

  for comment in comments:
    print("\t// " + comment)

  for chunk in Chunker(pics, 5):
    t = ""
    for pic in chunk:
      t = t + "{ " + str(pic[0]).rjust(3, ' ') + ", " + str(pic[1]).rjust(2, ' ') + " }, "
    print("\t" + t)

  print("};")

def PrintView(views, comments):
  print("static const ViewMod viewMods" + GID + "[] = {")

  for comment in comments:
    print("\t// " + comment)

  for chunk in Chunker(views, 5):
    t = ""
    for view in chunk:
      t = t + "{ " + str(view[0]).rjust(3, ' ') + ", " + str(view[1]).rjust(2, ' ') + ", " + str(view[2]).rjust(2, ' ') + ", " + str(view[3]).rjust(2, ' ') + " }, "
    print("\t" + t)

  print("};")

def ParseList(l):
  assert(l[0] == '(')
  e = l.find(")")
  L = l[1:e].split(",")
  tests = []
  for t in L:
    t = t.strip()
    ell = t.find('..')
    if ell >= 0:
      start = int(t[0:ell])
      end = int(t[ell+2:])
      # interval
      for x in range(start, end + 1):
        tests.append(x)
    else:
      tests.append(t)
  return l[e+1:], tests

def ParseTriple(l):
  assert(l[0] == '(')
  e = l.find(")")
  L = l[1:e].split(",")
  assert(len(L) == 3)
  return L

GIDs = []

for F in sys.argv[1:]:
  comments = []
  pics = []
  views = []
  Mods = [(1.,1.,1.)]
  GID = ""

  for l in open(F, "r").readlines():
    l = l.strip()
    if len(l) == 0:
      continue
    if l[0] == '#':
      comment = l[1:].strip()
      # Only add the top comments (before the game ID is set)
      if (GID == ""):
        comments.append(comment)
      continue
    if l[0:6] == "gameid":
      assert(GID == "")
      l = l[6:].strip()
      l = l.strip()
      assert(l[0] == "=")
      assert(l[-1] == ";")
      l = l[1:-1].strip()
      GID = l
      continue
    if l[0:4] == "view":
      ruletype = "view"
      l = l[4:]
    elif l[0:3] == "pic":
      ruletype = "pic"
      l = l[3:]
    else:
      assert(False)
  
    ids = []
    loops = [-1]
    cels = [-1]
    l,ids = ParseList(l)
    if l[0] == "(":
      l,loops = ParseList(l)
    if l[0] == "(":
      l,cels = ParseList(l)
    l = l.strip()
    assert(l[0:2] == "*=")
    assert(l[-1] == ";")
    l = l[2:-1].strip()
    if l[0] == "(":
      val = ParseTriple(l)
      val = (float(v) for v in val)
    else:
      val = (float(l), float(l), float(l))
    if ruletype == "pic":
      for pic in ids:
        pics.append([pic, ModToIndex(val)])
    elif ruletype == "view":
      for view in ids:
        for loop in loops:
          for cel in cels:
            views.append([view, loop, cel, ModToIndex(val)])

  if GID == "":
    raise ValueError("No gameid specified")

  GIDs.append(GID)

  PrintMods()
  print()
  PrintPic(pics, comments)
  print()
  PrintView(views, comments)
  print()

print("static const SciFxMod mods[] = {")
for GID in GIDs:
  print("\t{{ GID_{0}, paletteMods{0}, ARRAYSIZE(paletteMods{0}), picMods{0}, ARRAYSIZE(picMods{0}), viewMods{0}, ARRAYSIZE(viewMods{0}) }},".format(GID));
print("};")

print("""
void setupCustomPaletteMods(GfxScreen *screen) {
	for (int i = 0; i < ARRAYSIZE(mods); i++) {
		if (mods[i].gameId == g_sci->getGameId()) {
			screen->setPaletteMods(mods[i].paletteMods, mods[i].paletteModsSize);
			break;
		}
	}
}

void doCustomViewPalette(GfxScreen *screen, GuiResourceId view, int16 loop, int16 cel) {
	for (int i = 0; i < ARRAYSIZE(mods); i++) {
		SciFxMod mod = mods[i];
		if (mod.gameId == g_sci->getGameId()) {
			for (int j = 0; j < mod.viewModsSize; j++) {
				ViewMod m = mod.viewMods[j];
				if (m.id == view && (m.loop == -1 || m.loop == loop) && (m.cel == -1 || m.cel == cel)) {
					screen->setCurPaletteMapValue(m.multiplier);
					break;
				}
			}
			break;
		}
	}
}

void doCustomPicPalette(GfxScreen *screen, GuiResourceId pic) {
	for (int i = 0; i < ARRAYSIZE(mods); i++) {
		SciFxMod mod = mods[i];
		if (mod.gameId == g_sci->getGameId()) {
			for (int j = 0; j < mod.picModsSize; j++) {
				PicMod m = mod.picMods[j];
				if (m.id == pic) {
					screen->setCurPaletteMapValue(m.multiplier);
					break;
				}
			}
			break;
		}
	}
}

}""")

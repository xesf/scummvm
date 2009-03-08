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
 * $URL$
 * $Id$
 *
 */

#ifndef SCI_GFX_FONT_H
#define SCI_GFX_FONT_H

#include "common/scummsys.h"


namespace Sci {

struct text_fragment_t {
	const char *offset;
	int length;
};


struct gfx_bitmap_font_t { /* gfx_bitmap_font_t: Bitmap font information */
	int ID; /* Unique resource ID */

	int chars_nr; /* Numer of available characters */

	int *widths; /* chars_nr character widths, in pixels */

	int row_size; /* Byte size of each pixel row. For unscaled fonts, this is
		      ** always 1, 2, or 4. Otherwise, it's a multiple of 4.
		      */

	int line_height; /* Height of each text line (usually identical to height) */
	int height; /* Height for all characters, in pixel rows */
	int char_size; /* Amount of memory occupied by one character in data */

	byte *data; /* Font data, consisting of 'chars_nr' entries of 'height' rows
		    ** of 'row_size' bytes. For each character ch, its first byte
		    ** (the topmost row) is located at (data + (charsize * ch)), and
		    ** its pixel width is widths[ch], provided that (ch < chars_nr).
		    */

};

/*******************/
/* Font operations */
/*******************/

/* SCI0, SCI01 and SCI1 all use the same font format. */

/* SQ3 uses a somewhat different scheme for calculating text sizes: it counts
** whitespace while calculating the text size.  */
#define GFXR_FONT_FLAG_COUNT_WHITESPACE (1<<0)
/* Don't give newline characters special semantics */
#define GFXR_FONT_FLAG_NO_NEWLINES (1<<1)
/* Interpret CR LF sequences as a single newline, rather than two of them */
#define GFXR_FONT_FLAG_EAT_TRAILING_LF (1<<2)


gfx_bitmap_font_t *gfxr_read_font(int id, byte *resource, int size);
/* Geneartes a bitmap font data structure from a resource
** Parameters: (int) id: Resource ID of the resulting font
**             (byte *) resource: Pointer to the resource data
**             (int) size: Size of the resource block
** Returns   : (gfx_bitmap_font_t *) The resulting font structure, or
**                                   NULL on error
*/

void gfxr_free_font(gfx_bitmap_font_t *font);
/* Frees a previously allocated font structure
** Parameters: (gfx_bitmap_font_t *) font: The font to free
** Returns   : (void)
*/

text_fragment_t *gfxr_font_calculate_size(gfx_bitmap_font_t *font, int max_width, const char *text,
	int *width, int *height, int *lines, int *line_height, int *last_offset, int flags);
/* Calculates the size that would be occupied by drawing a specified text
** Parameters: (gfx_bitmap_font_t *) font: The font to calculate with
**             (int) max_width: Maximum pixel width allowed for the output
**             (const char *) text: The text to calculate for
**             (int) flags: Any text formatting flags
** Returns   : (text_fragment *) a newly allocated array of text_fragments,
**                               containing the start and size of each string
**                               segment
**             (int) *width: The resulting width
**             (int) *height: The resulting height
**             (int) *lines: Number of lines used
**             (int) *line_height: Pixel height of a single line of text
**             (int) *last_offset: Pixel offset after the last drawn line
** This function assumes 320x200 mode.
*/

gfx_pixmap_t *gfxr_draw_font(gfx_bitmap_font_t *font, const char *text, int characters,
	PaletteEntry *fg0, PaletteEntry *fg1, PaletteEntry *bg);
/* Draws text in a specific font to a pixmap
** Parameters: (gfx_bitmap_font_t *) font: The font to use for drawing
**             (char *) text: The start of the text to draw
**             (int) characters: The number of characters to draw
**             (gfx_pixmap_color_t *) fg0: The first foreground color
**             (gfx_pixmap_color_t *) fg1: The second foreground color
**             (gfx_pixmap_color_t *) bg: The background color
** Returns   : (gfx_pixmap_t *) The result pixmap, or NULL on error
** The results are written to the pixmap's index buffer. Contents of the
** foreground and background fields are copied into a newly allocated font
** structure, so that the pixmap may be translated directly.
** If any of the colors is null, it will be assumed to be transparent.
** In color index mode, the specified colors have to be preallocated.
*/

} // End of namespace Sci

#endif // SCI_GFX_FONT_H

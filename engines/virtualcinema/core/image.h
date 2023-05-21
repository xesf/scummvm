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

#ifndef VIRTUALCINEMA_IMAGE_H
#define VIRTUALCINEMA_IMAGE_H

#include "common/array.h"
#include "common/list.h"
#include "common/noncopyable.h"
#include "common/ptr.h"
#include "common/rational.h"
#include "graphics/pixelformat.h"
#include "image/bmp.h"

namespace VirtualCinema {

class VCEngine;

/**
 * A image monitored by the ImageManager
 */
class ImageEntry : private Common::NonCopyable {
    // The private members should be able to be manipulated by ImageManager
    friend class ImageManager;

private:
    ImageEntry();
    ImageEntry(Image::BitmapDecoder *image, const Common::String &fileName);
    ImageEntry(Image::BitmapDecoder *image);

public:
    ~ImageEntry();

    operator bool() const { return isOpen(); }
    bool isOpen() const { return _image != 0; }
    void close();
    uint16 getX() const { return _x; }
    uint16 getY() const { return _y; }
    bool isEnabled() const { return _enabled; }
    const Common::String &getFileName() const { return _fileName; }
    void setX(uint16 x) { _x = x; }
    void setY(uint16 y) { _y = y; }
    void moveTo(uint16 x, uint16 y) { setX(x); setY(y); }
    void center();
    void setEnabled(bool enabled) { _enabled = enabled; }

    uint16 getWidth();
    uint16 getHeight();
    Common::Rect getRect();
    void setRect(uint16 x, uint16 y, uint16 w, uint16 h);

private:
    Image::BitmapDecoder *_image;
    Graphics::Surface *_surface;
    Common::String _fileName;
    Common::Rect _rect;

    uint16 _x;
    uint16 _y;
    bool _enabled;
};

typedef Common::SharedPtr<ImageEntry> ImageEntryPtr;

class ImageManager {
public:
    explicit ImageManager(VCEngine *vm);
    virtual ~ImageManager();

    // Generic image functions
    ImageEntryPtr show(const Common::String &filename);
    bool updateImages();
    void closeImages();
    
    // Utility functions for managing entries
    ImageEntryPtr openFile(const Common::String &filename);
    
    // Handle functions
    ImageEntryPtr findImage(const Common::String &fileName);
    void removeEntry(const ImageEntryPtr &image);

protected:
    VCEngine *_vm;

    // Keep tabs on any images playing
    typedef Common::List<ImageEntryPtr> ImageList;
    ImageList _images;

    ImageList::iterator findEntry(ImageEntryPtr ptr);

    bool drawImage(ImageEntryPtr ImageEntry);
};

} // End of namespace VirtualCinema

#endif

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

#include "common/algorithm.h"
#include "common/debug.h"
#include "common/events.h"
#include "common/textconsole.h"
#include "common/system.h"
#include "common/file.h"

#include "graphics/palette.h"
#include "graphics/surface.h"
#include "image/bmp.h"

#include "virtualcinema/core/vcengine.h"
#include "virtualcinema/core/image.h"

namespace VirtualCinema {

ImageEntry::ImageEntry() : _image(nullptr), _x(0), _y(0), _enabled(true) {
}

ImageEntry::ImageEntry(Image::BitmapDecoder *image, const Common::String &fileName) : _image(image), _fileName(fileName), _x(0), _y(0), _enabled(true) {
}

ImageEntry::ImageEntry(Image::BitmapDecoder *image) : _image(image), _x(0), _y(0), _enabled(true) {
}

ImageEntry::~ImageEntry() {
    close();
}

void ImageEntry::close() {
    delete _surface;
    delete _image;
    _image = nullptr;
    _surface = nullptr;
}

void ImageEntry::center() {
    assert(_image);
    _x = (g_system->getWidth() - getWidth()) / 2;
    _y = (g_system->getHeight() - getHeight()) / 2;
}

uint16 ImageEntry::getWidth() {
    assert(_image);
    return _image->getSurface()->w;
}

uint16 ImageEntry::getHeight() {
    assert(_image);
    return _image->getSurface()->h;
}

Common::Rect ImageEntry::getRect() {
    return Common::Rect(_x, _y, _x + getWidth(), _y + getHeight());
}

// ---------------------------------------------------------------------------------

ImageManager::ImageManager(VCEngine *vm) : _vm(vm) {
}

ImageManager::~ImageManager() {
    closeImages();
}

void ImageManager::closeImages() {
    for (ImageList::iterator it = _images.begin(); it != _images.end(); it++)
        (*it)->close();

    _images.clear();
}

ImageEntryPtr ImageManager::show(const Common::String &fileName) {
    debug("Showing image: %s", fileName.c_str());
    ImageEntryPtr ptr = openFile(fileName);
    ptr->center();
    if (!ptr)
        return ImageEntryPtr();

    return ptr;
}

ImageEntryPtr ImageManager::openFile(const Common::String &fileName) {
    // If this image is already showed
    ImageEntryPtr oldImage = findImage(fileName);
    if (oldImage)
        return oldImage;

    Common::File file;
    if (!file.open(fileName))
        error("unable to load image %s", fileName.c_str());
    Image::BitmapDecoder *image = new Image::BitmapDecoder();
    image->loadStream(file);
    file.close();

    // Create the entry
    ImageEntryPtr entry(new ImageEntry(image, fileName));

    // Convert the image to the screen format
    entry.get()->_surface = image->getSurface()->convertTo(_vm->_system->getScreenFormat(), image->getPalette(), image->getPaletteColorCount());

    // Add it to the image list
    _images.push_back(entry);

    return entry;
}

ImageEntryPtr ImageManager::findImage(const Common::String &fileName) {
    if (fileName.empty())
        return ImageEntryPtr();

    for (ImageList::iterator it = _images.begin(); it != _images.end(); it++)
        if ((*it)->getFileName().equalsIgnoreCase(fileName))
            return *it;

    return ImageEntryPtr();
}

ImageManager::ImageList::iterator ImageManager::findEntry(ImageEntryPtr ptr) {
    return Common::find(_images.begin(), _images.end(), ptr);
}

void ImageManager::removeEntry(const ImageEntryPtr &video) {
    ImageManager::ImageList::iterator it = findEntry(video);
    if (it != _images.end())
        _images.erase(it);
}

bool ImageManager::updateImages() {
    bool updateScreen = false;

    for (ImageList::iterator it = _images.begin(); it != _images.end(); ) {
        ImageEntry *entry = (*it).get();

        // skip if not enabled
        if (!entry->isEnabled()) {
            it++;
            continue;
        }

        // Check if we need to draw the image
        if (drawImage(*it)) {
            updateScreen = true;
        }

        // Remember to increase the iterator
        it++;
    }

    // Return true if we need to update the screen
    return updateScreen;
}

// void ImageManager::drawImage(const ImageEntryPtr &image) {
//     assert(image);
//     drawImage(image);
// }

bool ImageManager::drawImage(ImageEntryPtr imageEntry) {
    // clip the image to make sure it stays on the screen
    Common::Rect targetRect = Common::Rect(imageEntry->_surface->w, imageEntry->_surface->h);
    targetRect.translate(imageEntry->getX(), imageEntry->getY());

    Common::Rect frameRect = Common::Rect(imageEntry->_surface->w, imageEntry->_surface->h);

    if (targetRect.left < 0) {
        frameRect.left -= targetRect.left;
        targetRect.left = 0;
    }

    if (targetRect.top < 0) {
        frameRect.top -= targetRect.top;
        targetRect.top = 0;
    }

    if (targetRect.right > _vm->_system->getWidth()) {
        frameRect.right -= targetRect.right - _vm->_system->getWidth();
        targetRect.right = _vm->_system->getWidth();
    }

    if (targetRect.bottom > _vm->_system->getHeight()) {
        frameRect.bottom -= targetRect.bottom - _vm->_system->getHeight();
        targetRect.bottom = _vm->_system->getHeight();
    }

    _vm->_system->copyRectToScreen(imageEntry->_surface->getBasePtr(frameRect.left, frameRect.top), imageEntry->_surface->pitch,
                                   targetRect.left, targetRect.top, targetRect.width(), targetRect.height());

    return true;
}

} // End of namespace VirtualCinema

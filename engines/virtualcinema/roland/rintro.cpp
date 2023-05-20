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
#include "common/file.h"
#include "common/system.h"
#include "graphics/surface.h"
#include "image/bmp.h"

#include "virtualcinema/core/eventHandler.h"

#include "rintro.h"

namespace VirtualCinema {

RIntro::RIntro(RolandEngine *vm): _vm(vm) {
}

RIntro::~RIntro() {
}

bool RIntro::mountEvent(const VCEvent &evt) {
    Common::File file;
    Common::String filename = Common::String::format("Intro%d.RLE", 1);
    if (!file.open(filename))
        error("unable to load image %s", filename.c_str());
    _image = new Image::BitmapDecoder();
    _image->loadStream(file);
    file.close();

    Graphics::Surface *screen = _image->getSurface()->convertTo(_vm->_system->getScreenFormat(), _image->getPalette(), _image->getPaletteColorCount());

    _vm->_system->copyRectToScreen(screen->getPixels(), screen->pitch, 0, 0, screen->w, screen->h);
    _vm->_system->updateScreen();

    delete screen;
    return true;
}

bool RIntro::unmountEvent(const VCEvent &evt) {
    return true;
}

bool RIntro::updateEvent(const VCEvent &evt) {
    return true;
}

bool RIntro::keyEvent(const VCEvent &evt) {
    return true;
}

bool RIntro::mouseEvent(const VCEvent &evt) {
    switch (evt.type) {
    case Common::EVENT_LBUTTONDOWN:
    case Common::EVENT_RBUTTONDOWN:
        _skip = true;
        break;
    default:
        break;
    }
    
    return true;
}

}

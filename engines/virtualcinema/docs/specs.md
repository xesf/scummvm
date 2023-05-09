# specs file

## x-files

### Quick Time Details

https://developer.apple.com/standards/qtff-2001.pdf

#### Audio Coded Missing in ScummVM
Missing audio codec implementation for location videos like: xv/64421.xmv | Seattle Office
Some format details can be found here: https://wiki.multimedia.cx/index.php/QDesign_Music_Codec

scummvm warning message:     
    Audio Codec Not Supported: 'QDMC'!

#### Subtitles Missing in ScummVM
stream-id: text

scummvm warning message:
    FSNode::createReadStream: 'rsrc' does not exist!

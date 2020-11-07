/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1999-2000 Revolution Software Ltd.
 * This code is based on source code created by Revolution Software,
 * used with permission.
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

#ifndef ICB_SPEECHMANAGER_H_INCLUDED_
#define ICB_SPEECHMANAGER_H_INCLUDED_

#include "engines/icb/common/px_common.h"
#include "engines/icb/sound/direct_sound.h"

#include "common/stream.h"

#include "audio/audiostream.h"
#include "audio/mixer.h"

namespace ICB {

class SpeechManager {
private:
	Audio::AudioStream *_audioStream;
	Audio::SoundHandle _handle;
	int m_speechVol; // The volume the each stream was started at

	uint32 m_wavByteOffsetInCluster;
	uint32 m_wavDataSize;

	bool8 m_paused;
	int m_lengthInCycles; // Assumes 12 frames per second

public:
	SpeechManager();
	~SpeechManager();

	bool8 UpdateSpeech();

	bool8 StartSpeech(const char *fileName, uint32 byteOffsetToWav, int32 vol = 128);
	void StopSpeech();
	void PauseSpeech();
	void ResumeSpeech();
	void SetSpeechVolume(int volume);
	bool8 IsPlaying();
	bool8 IsPaused() { return m_paused; }
	int GetLength() { return m_lengthInCycles; }

private:
	bool8 OpenSpeech(Common::SeekableReadStream *stream);
	void KillBuffer();
	void SetVolume(int volume);
};

} // End of namespace ICB

#endif

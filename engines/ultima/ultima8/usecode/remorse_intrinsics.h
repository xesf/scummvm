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

#ifndef ULTIMA8_USECODE_REMORSEINTRINSICS_H
#define ULTIMA8_USECODE_REMORSEINTRINSICS_H

#include "ultima/ultima8/usecode/intrinsics.h"
#include "ultima/ultima8/world/item.h"

namespace Ultima {
namespace Ultima8 {

// Crusader: No Remorse Intrinsics
// Unknown function signatures were generate by the usecode disassembly
// and looking at handling of SP and retval after function.
// Most up-to-date version of unknown functions is in convert_usecode_crusader.h
Intrinsic RemorseIntrinsics[] = {
	// 0x000
	Ultima8Engine::I_getAlertActive,  // basically confirmed.. see eg, ALARM_NS::enterFastArea - set frame for alert siren based on value.
	Item::I_getFrame, // ? int Intrinsic001(4 bytes)
	Item::I_setFrame, // basically confirmed..
	Item::I_getMapArray, // See TRIGGER::ordinal21 - stored in a variable 'mapNum'
	Item::I_getStatus, // probably - see usage in GATGUNEW::enterFastArea - always followed by an AND against a single bit
	Item::I_orStatus, // probably - see usage in GATGUNEW::enterFastArea
	Item::I_equip, // void Intrinsic006(6 bytes)
	0, // ? byte Item::I_getSOMETHING_07(Item *)
	Actor::I_isNPC, // byte Intrinsic008(Item *) // probably.. disasm checks for < 256
	Item::I_getZ, // byte Intrinsic009(4 bytes) // probably, see PEPSIEW::use() variable names
	Item::I_destroy, // void Intrinsic00A(4 bytes) // probably, often called after creating replacement object in same position eg, LUGGAGE::gotHit
	0, // something with npcdata void Intrinsic00B(4 bytes)
	0, // void Intrinsic00C(2 bytes)
	Item::I_getDirToItem, // byte Intrinsic00D(6 bytes)
	0, // int Intrinsic00E(8 bytes)
	0, // based on TESTFLIC, appears to be I_playVideo(item*, char *vidname, int16 sizex, int16 sizey)
	// 0x010
	Item::I_getQLo, // Based on having same coff as 02B
	Actor::I_getMap, // int Intrinsic011(4 bytes)
	0, // void Intrinsic012(2 bytes)
	Item::I_getX, //int Intrinsic013(4 bytes) // probably - see FREE::ordinal34
	Item::I_getY, //int Intrinsic014(4 bytes) // probably - see FREE::ordinal34
	AudioProcess::I_playSFXCru, // pretty sure, see SWITCH::ordinal21 which plays various sfx related to access status
	Item::I_getShape, // in STEAMBOX::func0A, is compared to 0x511 (the STEAM2 shape number) to determine direction
	0, // void Intrinsic017(8 bytes)
	UCMachine::I_rndRange, // int16 Intrinsic018(4 bytes) // probably.. always called with 2 constants, then result compared to some number between
	Item::I_legalCreateAtCoords, // byte Intrinsic019(14 bytes),  probably, see usage in DOOR2::ordinal37
	Item::I_andStatus, // void Intrinsic01A(6 bytes)
	0, // // different than U8's? int Intrinsic01B(void)
	Actor::I_getDir, // byte Intrinsic01C(4 bytes)
	Actor::I_getLastAnimSet, // int Intrinsic01D(4 bytes)
	0, // int Intrinsic01E(16 bytes)
	Item::I_create, // probably - used in MISS1EGG creating keycards and NPCDEATH in creating blood spills
	// 0x020
	Item::I_popToCoords, // void Intrinsic020(10 bytes)
	Actor::I_setDead, // void Intrinsic021(4 bytes)
	Item::I_push,
	0, // int Intrinsic023(void)
	Item::I_setShape, // Probably, see PEPSIEW::gotHit
	Item::I_touch,
	Item::I_getQHi, // int16 Intrinsic026(Item *), // guess, based on variable name in BOUNCBOX::gotHit
	0, // int Intrinsic027(14 bytes)
	Item::I_hurl, // int Intrinsic028(12 bytes)
	0, // int Intrinsic029(void)
	AudioProcess::I_playAmbientSFXCru, // Confirmed!
	Item::I_getQLo, // int16 Intrinsic02B(4 bytes), // guess, based on variable name in BOUNCBOX::gotHit
	Item::I_inFastArea, // byte Intrinsic02C(4 bytes) // based on disassembly - checks for flag 0x2000
	Item::I_setQHi,
	Item::I_legalMoveToPoint, // byte Intrinsic02E(12 bytes)
	0, // byte Intrinsic02F(10 bytes)
	// 0x030
	Item::I_pop,
	Item::I_andStatus,
	0, // void Intrinsic032(12 bytes)
	Actor::I_isBusy, // int Intrinsic033(4 bytes)
	0, // TODO: void Actor::I_getDir16(8 bytes)
	0, // int Intrinsic035(4 bytes)
	Actor::I_doAnim, // void Intrinsic036(12 bytes)
	0, // int Intrinsic037(4 bytes)
	AudioProcess::I_stopSFXCru, // takes Item *, sndno (from disasm)
	Actor::I_isDead, // int Intrinsic039(4 bytes)
	0, // something with sound maybe? int Intrinsic03A(6 bytes)
	Item::I_setQLo,
	Item::I_getFamily,
	Container::I_destroyContents,
	0, // void Intrinsic03E(4 bytes)
	Egg::I_getEggId, // void Intrinsic03F(4 bytes)
	// 0x040
	CameraProcess::I_move_to, // void Intrinsic040(8 bytes)
	CameraProcess::I_setCenterOn, // void Intrinsic041(2 bytes)
	0, // int Intrinsic042(6 bytes)
	0, // void Intrinsic043(6 bytes) // maybe stopSFX (based on coff)
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	// 0x050
	0, // void Intrinsic050(4 bytes)
	0, // void Intrinsic051(4 bytes)
	0, // void Intrinsic052(6 bytes)
	0, // void Intrinsic053(6 bytes)
	0, // void Intrinsic054(6 bytes)
	0, // void Intrinsic055(6 bytes)
	0, // void Intrinsic056(2 bytes)
	0, // void Intrinsic057(4 bytes)
	0, // ? Item::I_setFrame, int Intrinsic058(6 bytes)
	Item::I_setFrame, // based on same coff as 002
	Actor::I_getLastAnimSet, // void Intrinsic05A(4 bytes)
	Item::I_legalCreateAtPoint, // probably. see PEPSIEW::use
	Item::I_getPoint, // void Intrinsic05C(8 bytes)
	0, // void Intrinsic05D(void)
	0, // int16 Intrinsic05E(uint32, char *, int16 a, int16 b)  // Play video (as texture? parameters like (150, 250, "MVA11A") and other mvas)
	0, // void Intrinsic05F(void)
	// 0x060
	Actor::I_setDead, // void Intrinsic060(4 bytes)
	Actor::I_create, // void Intrinsic061(8 bytes)
	0, // void Intrinsic062(void)
	Actor::I_teleport, // void Intrinsic063(12 bytes)
	Item::I_getFootpadData, // void Intrinsic064(16 bytes)
	0, // TODO: Item::I_isInNPC
	Item::I_getQLo, // based on same coff set as 02B
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_setNpcNum, // void Item::I_setSomething068(Item *, int16 something) , see VALUEBOX:ordinal20
	Item::I_andStatus, // void Intrinsic069(6 bytes)
	Item::I_move, // void Intrinsic06A(10 bytes)
	0, // int16 Intrinsic06B(void)
	0, // void Intrinsic06C(4 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // void Intrinsic06E(6 bytes)
	0, // TODO: Item::I_isCompletelyOn int Intrinsic06F(6 bytes)
	// 0x070
	0, // int Intrinsic070(void)
	0, // void Intrinsic071(void)
	0, // void Intrinsic072(void)
	Actor::I_setDead,
	0, // void Intrinsic074(void)
	0, // void Intrinsic075(void)
	AudioProcess::I_stopSFXCru, // takes Item *, from disasm
	0, // ? Item::I_getQuality, void Intrinsic077(void)
	0, // ? Item::I_setQuality, void Intrinsic078(void)
	MainActor::I_teleportToEgg, // different than U8's? void Intrinsic079(6 bytes)
	0, // void Intrinsic07A(void)
	Actor::I_clrImmortal, // based on disasm
	0, // void Intrinsic07C(4 bytes) // I_getQIfSomething, see disassembly
	0, // ? Item::I_getQLo, void Intrinsic07D(6 bytes)
	Item::I_getQuality,
	Item::I_setQuality,
	// 0x080
	Item::I_use, // void Intrinsic080(4 bytes)
	0, // void Intrinsic081(4 bytes)
	0, // ? Item::I_getNpcNum, void Intrinsic082(4 bytes)
	0, // void Intrinsic083(6 bytes)
	Item::I_getQLo, // based on same coff set as 02B
	Actor::I_setImmortal, // void Intrinsic085(4 bytes)
	0, // void Intrinsic086(void)
	0, // void Intrinsic087(void)
	Item::I_setMapArray, // maybe I_setNpcNum -- based on use for VALUEBOX (like getNPCNum is) and coff being right next to getNPCNum.. see VALUEBOX:ordinal20.  Could also be I_setMapArray??
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	0, // void Intrinsic08A(12 bytes)
	Item::I_enterFastArea, // void Intrinsic08B(4 bytes)
	0, // void Intrinsic08C(4 bytes)
	Item::I_hurl, // void Intrinsic08D(12 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	0, // void Intrinsic08F(void)
	// 0x090
	0, // void Intrinsic090(void)
	0, // void Intrinsic091(void)
	0, // I_playFlic(char *)? void Intrinsic092(void)
	0, // void Intrinsic093(void)
	0, // UNUSEDInt0094()
	0, // int Intrinsic095(void) // get global - something about keyboard (by disasm)
	MainActor::I_teleportToEgg, // void Intrinsic096(4 bytes)
	0, // void Intrinsic097(void)
	0, // void Intrinsic098(void)
	Item::I_andStatus, // void Intrinsic099(6 bytes)
	0, // ? Item::I_getQLo, void Intrinsic09A(void)
	0, // ? Item::I_getUnkEggType, void Intrinsic09B(2 bytes)
	0, // void Intrinsic09C(4 bytes)
	0, // void Intrinsic09D(2 bytes)
	0, // void Intrinsic09E(4 bytes)
	0, // void Intrinsic09F(10 bytes)
	// 0x0A0
	Actor::I_setDead,
	Item::I_getQLo, // based on same coff set as 02B
	Item::I_getUnkEggType,
	Egg::I_setEggXRange, // void Intrinsic0A3(6 bytes)
	Item::I_overlaps,
	Item::I_isOn,
	0, // ? Item::I_getNpcNum, void Intrinsic0A6(void)
	Egg::I_getEggXRange, // ? Item::I_getQLo, void Intrinsic0A7(4 bytes)
	Actor::I_setDead,
	0, // I_playFlic(char *) Intrinsic0A9(void)
	AudioProcess::I_playSFX, // void Intrinsic0AA(2 bytes)
	0, // ? Item::I_andStatus, int Intrinsic0AB(4 bytes)
	0, // ? Ultima8Engine::I_getCurrentTimerTick, void Intrinsic0AC(2 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_getQLo, // based on same coff set as 02B
	Item::I_getQHi,  // based on same coff set as 026
	// 0x0B0
	Item::I_unequip, // void Intrinsic0B0(6 bytes)
	Item::I_avatarStoleSomething, // void Intrinsic0B1(6 bytes)
	Item::I_andStatus, // void Intrinsic0B2(6 bytes)
	Ultima8Engine::I_getCurrentTimerTick, // int32 Intrinsic0B3(void), probably, see FREE::ordinal32
	0, // void Intrinsic0B4(void)
	Item::I_equip, // void Intrinsic0B5(6 bytes)
	0, // ? Item::I_getQHi, void Intrinsic0B6(void)
	0, // ? Item::I_andStatus, void Intrinsic0B7(void)
	0, // int Intrinsic0B8(4 bytes)
	Actor::I_getLastAnimSet, // void Intrinsic0B9(4 bytes)
	Item::I_setQuality,
	0, // ? Item::I_andStatus, int Intrinsic0BB(8 bytes)
	Item::I_isOn,
	Item::I_hurl, // void Intrinsic0BD(12 bytes)
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_andStatus, // void Intrinsic0BF(6 bytes)
	// 0x0C0
	Item::I_hurl, // void Intrinsic0C0(12 bytes)
	Item::I_andStatus, // void Intrinsic0C1(6 bytes)
	Item::I_hurl, // void Intrinsic0C2(12 bytes)
	Item::I_andStatus, // void Intrinsic0C3(6 bytes)
	0, // void Intrinsic0C4(2 bytes)
	Item::I_isOn,
	SpriteProcess::I_createSprite, // void Intrinsic0C6(14 bytes)
	Item::I_getDirFromItem, // int Intrinsic0C7(6 bytes)
	Item::I_hurl, // void Intrinsic0C8(12 bytes)
	Item::I_getQHi,  // based on same coff set as 026
	0, // int Intrinsic0CA(6 bytes)
	0, // void Intrinsic0CB(2 bytes)
	0, // int Intrinsic0CC(4 bytes)
	0, // void Intrinsic0CD(6 bytes)
	0, // void Intrinsic0CE(void)
	0, // void Intrinsic0CF(6 bytes)
	// 0x0D0
	Item::I_use, // void Intrinsic0D0(4 bytes)
	0, // 0D1 - I_StopAllSFX (unused so not implmeneted)
	0, // void I_playFlic(int *item,char *flicname,word sizex,word sizey) // play flic
	0, // UNUSEDInt00D3()
	AudioProcess::I_playSFX, // void Intrinsic0D4(2 bytes)
	Item::I_use, // void Intrinsic0D5(4 bytes)
	0, // int Intrinsic0D6(void)
	Actor::I_getLastAnimSet, // void Intrinsic0D7(4 bytes)
	Actor::I_setDead,
	Item::I_getQLo, // based on same coff set as 02B
	0, // void Intrinsic0DA(void)
	0, // void Intrinsic0DB(6 bytes)
	Item::I_isOn,
	0, // void Intrinsic0DD(4 bytes)
	0, // void Intrinsic0DE(6 bytes)
	Actor::I_getEquip, // void Intrinsic0DF(6 bytes)
	// 0x0E0
	Actor::I_setEquip, // void Intrinsic0E0(8 bytes)
	0, // void Intrinsic0E1(4 bytes)
	0, // ? Item::I_andStatus, void Intrinsic0E2(4 bytes)
	0, // ? Item::I_getQLo, void Intrinsic0E3(4 bytes)
	Actor::I_getLastAnimSet, // void Intrinsic0E4(4 bytes)
	0, // void Intrinsic0E5(6 bytes)
	0, // ? Item::I_popToContainer, void Intrinsic0E6(6 bytes)
	Actor::I_setDead,
	Item::I_cast, // void Intrinsic0E8(6 bytes)
	Item::I_andStatus, // void Intrinsic0E9(6 bytes)
	Item::I_getQLo, // based on same coff set as 02B
	0, // void Intrinsic0EB(void)
	Item::I_popToEnd,
	Item::I_popToContainer,
	0, // ? Item::I_setQ, void Intrinsic0EE(void)
	0, // void Intrinsic0EF(4 bytes)
	// 0x0F0
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_isOn,
	0, // void Intrinsic0F2(6 bytes)
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_getQ, // void Intrinsic0F4(4 bytes)
	Item::I_setQ, // void Intrinsic0F5(6 bytes)
	0, // void Intrinsic0F6(void)
	Item::I_hurl, // void Intrinsic0F7(12 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_hurl, // void Intrinsic0F9(12 bytes)
	Item::I_isOn,
	Item::I_getQHi,  // based on same coff set as 026
	Item::I_andStatus, // void Intrinsic0FC(6 bytes)
	0, // ? Item::I_getNpcNum, int Intrinsic0FD(2 bytes)
	0, // void Intrinsic0FE(4 bytes)
	UCMachine::I_numToStr, // same as 113 based on same coff set 0FF, 113, 126
	// 0x100
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // ? Item::I_getNpcNum, void Intrinsic101(6 bytes)
	Item::I_getNpcNum, // Based on variable name in TRIGGER::ordinal21
	0, // ? Item::I_getNpcNum, // byte Intrinsic103(uint16 shapenum),

	Item::I_andStatus, // void Intrinsic104(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // void Intrinsic106(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // void Intrinsic108(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // void Intrinsic10A(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // void Intrinsic10C(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_andStatus, // void Intrinsic10E(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	// 0x110
	Item::I_andStatus, // void Intrinsic110(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Actor::I_getDir, // byte Intrinsic112(4 bytes)
	UCMachine::I_numToStr, // see VMAIL::func0A for example usage
	Item::I_andStatus, // void Intrinsic114(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	0, // ? Item::I_getTypeFlag, byte Intrinsic116(14 bytes)
	Item::I_andStatus, // ? Item::I_getNpcNum, void Intrinsic117(6 bytes)
	Item::I_hurl, // int16 Intrinsic118(12 bytes)
	0, // void Intrinsic119(4 bytes)
	Item::I_andStatus, // void Intrinsic11A(6 bytes)
	0, // byte Intrinsic11B(6 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Item::I_hurl, // int16 Intrinsic11D(12 bytes)
	0, // int16 Intrinsic11E(4 bytes)
	0, // ? Item::I_getNpcNum, byte Intrinsic11F(4 bytes)
	// 0x120
	0, // void Intrinsic120(4 bytes)
	Actor::I_getDir, // int Intrinsic121(4 bytes)
	Actor::I_isDead, // int Intrinsic122(4 bytes)
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	Actor::I_getLastAnimSet, // void Intrinsic124(4 bytes)
	Item::I_setQuality,
	UCMachine::I_numToStr, // same as 113 based on same coff set 0FF, 113, 126
	Item::I_getDirToCoords, // int Intrinsic127(8 bytes)
	Item::I_andStatus, // void Intrinsic128(6 bytes) // maybe Item::andStatus?? see ITEM::ordinal22
	Item::I_getNpcNum, // based on same coff as 102 (-> variable name in TRIGGER::ordinal21)
	0, // void Intrinsic12A(4 bytes)
	0, // void Intrinsic12B(4 bytes)
	Item::I_isOn,
	Item::I_getFootpadData, // void Intrinsic12D(16 bytes)
	Actor::I_isDead, // int Intrinsic12E(4 bytes)
	0, // ? Item::I_getQHi, void Intrinsic12F(6 bytes)
	// 0x130
	Actor::I_clrImmortal, // void Intrinsic130(4 bytes)
	0, // void Intrinsic131(6 bytes)
	Item::I_andStatus, // void Intrinsic132(6 bytes)
	Item::I_getQHi,  // based on same coff set as 026
    0, // void Intrinsic134(2 bytes)
    Actor::I_setDead,
    0, // void UNUSEDInt136()
    0  // void UNUSEDInt137()
};

} // End of namespace Ultima8
} // End of namespace Ultima

#endif

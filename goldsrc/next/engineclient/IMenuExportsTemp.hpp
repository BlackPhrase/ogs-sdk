/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2018, 2020 BlackPhrase
 *
 * OGSNext Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGSNext Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGSNext Engine. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#pragma once

#include "const.h"
#include "tier1/interface.h"

constexpr auto OGS_MENUEXPORTS_INTERFACE_VERSION{"OGSMenuExports000"};

/*
#ifndef qpic_t
typedef struct
{
	int width, height;
	byte data[4]; // variably sized
} qpic_t;
#endif
*/

typedef struct qpic_s qpic_t;
typedef struct vmode_s vmode_t;

typedef void (*xcommand_t)();

struct IMenuExportsTemp : public IBaseInterface
{
	virtual void Cbuf_AddText(const char *text) = 0;
	virtual void Cbuf_InsertText(const char *text) = 0;
	
	virtual void Cmd_AddCommand(const char *name, xcommand_t function) = 0;
	
	virtual void Cvar_Set(const char *name, const char *value) = 0;
	virtual void Cvar_SetValue(const char *name, float value) = 0;
	virtual const char *Cvar_VariableString(const char *name) const = 0;
	virtual float Cvar_VariableValue(const char *name) const = 0;
	
	virtual void S_LocalSound(const char *sample) = 0;
	
	virtual void S_ExtraUpdate() = 0;
	
	virtual void Draw_FadeScreen() = 0;
	virtual void Draw_ConsoleBackground(int lines) = 0;
	virtual qpic_t *Draw_CachePic(const char *name) = 0;
	virtual void Draw_Character(int x, int y, int num) = 0;
	virtual void Draw_Pic(int x, int y, qpic_t *pic) = 0;
	virtual void Draw_TransPic(int x, int y, qpic_t *pic) = 0;
	virtual void Draw_TransPicTranslate(int x, int y, qpic_t *pic, byte *translation) = 0;
	
	virtual void VID_LockBuffer() = 0;
	virtual void VID_UnlockBuffer() = 0;
	virtual int VID_GetWidth() const = 0;
	virtual int VID_GetHeight() const = 0;
	virtual bool VID_IsWindowed() const = 0;
	virtual int VID_GetCurrentModeNum() const = 0;
	virtual int VID_NumModes() const = 0;
	virtual const char *VID_GetModeDescription(int mode) const = 0;
	virtual vmode_t *VID_GetModePtr(int mode) const = 0;
	
	virtual void SCR_BeginLoadingPlaque() = 0;
	virtual int SCR_ModalMessage(const char *msg) = 0;
	virtual void SCR_SetFullUpdateActive(bool abActive) = 0;
	virtual void SCR_SetCopyEverything(bool abActive) = 0;
	virtual float SCR_Con_Current() const = 0;
	
	virtual double Host_GetTime() const = 0;
	virtual void Host_Quit_f() = 0;
	
	virtual const char *Key_KeynumToString(int keynum) = 0;
	virtual void Key_SetBinding(int key, const char *cmd) = 0;
	virtual const char *Key_GetBinding(int key) const = 0;
	
	virtual void Con_ToggleConsole_f() = 0;
	
	virtual void SetKeyDest(int nDest) = 0;
	virtual int GetKeyDest() const = 0;
	
	virtual void CL_SetDemoNum(int nNum) = 0;
	virtual int CL_GetDemoNum() const = 0;
	virtual bool CL_DemoPlayback() const = 0;
	virtual bool CL_IsConnected() const = 0;
	virtual void CL_NextDemo() = 0;
	virtual int CL_Intermission() const = 0;
	
	virtual double Host_GetRealTime() const = 0;
	virtual bool Host_IsServerActive() const = 0;
	
	virtual int GetMaxClients() const = 0;
	virtual int GetMaxClientsLimit() const = 0;
	
	virtual const char *GetGameDir() const = 0;
};
/*
 * This file is part of OGS Engine
 * Copyright (C) 2016-2019 BlackPhrase
 *
 * OGS Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS Engine. If not, see <http://www.gnu.org/licenses/>.
 */

/// @file
/// @brief dedicated server launcher interface

#pragma once

#include "public/interface.h"

const char VENGINE_HLDS_API_VERSION[] = "VENGINE_HLDS_API_VERSION002";

struct IDedicatedServerAPI : public IBaseInterface
{
	/// Initialize the engine in dedicated server mode
	/// @param basedir - a game directory to use as a base
	/// @param cmdline - an application startup command line arguments string
	/// @param launcherFactory - a function pointer to the application's interface factory
	/// @param filesystemFactory - a function pointer to the file system module's interface factory
	/// @return true if success
	virtual bool Init(const char *basedir, const char *cmdline, CreateInterfaceFn launcherFactory, CreateInterfaceFn filesystemFactory) = 0;
	
	/// Shutdown the engine
	/// @return ???
	virtual int Shutdown() = 0;
	
	/// Try to run a single frame
	/// @return true if success
	virtual bool RunFrame() = 0;
	
	/// Add the specified text to command buffer to execute it
	/// @param text - a string for execution
	virtual void AddConsoleText(const char *text) = 0;
	
	/// Update host status
	virtual void UpdateStatus(float *fps, int *nActive, int *nMaxPlayers, char *pszMap) = 0;
};
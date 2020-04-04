/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2015-2020 BlackPhrase
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
/// @brief Game UI console panel interface

#pragma once

#include "CommonTypes.hpp"
#include "Interface.hpp"

constexpr auto OGS_GAMECONSOLE_INTERFACE_VERSION{"OGSGameConsole001"};

//class Color;

interface IGameConsole : public IBaseInterface
{
	///
	virtual void Init() = 0;
	
	/// @param abActive - true activates the console, makes it visible and brings it to the foreground, false hides the console
	virtual void SetActive(bool abActive) = 0; // TODO: SetVisible?
	
	/// @return true if the console has focus
	virtual bool IsVisible() const = 0; // TODO: IsActive?
	
	/// Clears the console
	virtual void Clear() = 0;
	
	/// Prints a message to the console
	virtual void Printf(const char *asMsg, ...) = 0;
	
	/// Prints a debug/dev message to the console
	virtual void DevPrintf(const char *asMsg, ...) = 0;
	
	///
	//virtual void SetTextColor(const Color &aColor) = 0;
	
	/// Prints a colored debug message to the console
	//virtual void ColorPrintf(const Color &aColor, const char *asMsg, ...) = 0;
	
	///
	//virtual void SetParent(int parent) = 0; // int = VPANEL
};
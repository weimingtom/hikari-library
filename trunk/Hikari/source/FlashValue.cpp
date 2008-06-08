/*
	This file is part of Hikari, a library that allows developers
	to use Flash in their Ogre3D applications.

	Copyright (C) 2008 Adam J. Simmons

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "FlashValue.h"

using namespace Hikari;

FlashValue::FlashValue() : numValue(0), boolValue(0), valueType(FT_NULL)
{
}

FlashValue::FlashValue(bool booleanValue) : numValue(0), boolValue(booleanValue), valueType(FT_BOOLEAN)
{
}

FlashValue::FlashValue(int numericValue) : numValue(numericValue), boolValue(0), valueType(FT_NUMBER)
{
}

FlashValue::FlashValue(Ogre::Real numericValue) : numValue(numericValue), boolValue(0), valueType(FT_NUMBER)
{
}

FlashValue::FlashValue(const char* stringValue) : strValue(stringValue), numValue(0), boolValue(0), valueType(FT_STRING)
{
}

FlashValue::FlashValue(const wchar_t* stringValue) : strValue(stringValue), numValue(0), boolValue(0), valueType(FT_STRING)
{
}

FlashValue::FlashValue(const Ogre::DisplayString& stringValue) : strValue(stringValue), numValue(0), boolValue(0), valueType(FT_STRING)
{
}

short FlashValue::getType() const
{
	return valueType;
}

bool FlashValue::isNull() const
{
	return valueType == FT_NULL;
}

void FlashValue::setNull()
{
	strValue.clear();
	numValue = 0;
	boolValue = false;
	valueType = FT_NULL;
}

bool FlashValue::getBool() const
{
	return boolValue;
}

Ogre::Real FlashValue::getNumber() const
{
	return numValue;
}

Ogre::ColourValue FlashValue::getNumberAsColor() const
{
	Ogre::ColourValue result;
	result.b = ((int)numValue % 256) / 255.0f;
	result.g = (((int)numValue / 256) % 256) / 255.0f;
	result.r = (((int)numValue / 256 / 256) % 256) / 255.0f;

	return result;
}

const Ogre::DisplayString& FlashValue::getString() const
{
	return strValue;
}

Args::Args()
{
}

Args::Args(Args &v)
{
	this->swap(v);
}

Args::Args(const FlashValue& firstArg) : Arguments(1, firstArg)
{
}

Args& Args::operator()(const FlashValue& newArg) 
{
	this->push_back(newArg);
	return *this;
}
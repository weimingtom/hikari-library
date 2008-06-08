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

#ifndef __FlashValue_H__
#define __FlashValue_H__

#include "Ogre.h"
#include "HikariPlatform.h"
#include <vector>

namespace Hikari {

/**
* Defines the Flash variable types, used by FlashValue.
*/
enum FlashType
{
	FT_NULL,
	FT_BOOLEAN,
	FT_NUMBER,
	FT_STRING
};

/**
* FlashValue represents a Flash ActionScript variable. The currently supported types are: null, boolean, number, and string.
*/
class _HikariExport FlashValue
{
	Ogre::DisplayString strValue;
	Ogre::Real numValue;
	bool boolValue;
	short valueType;
public:
	/**
	* Creates a null FlashValue.
	*/
	FlashValue();

	/**
	* Creates a FlashValue as a boolean type.
	*
	* @param	booleanValue	The value to initialize this FlashValue with.
	*/
	FlashValue(bool booleanValue);

	/**
	* Creates a FlashValue as a number type.
	*
	* @param	numericValue	The value to initialize this FlashValue with.
	*/
	FlashValue(int numericValue);
	
	/**
	* Creates a FlashValue as a number type.
	*
	* @param	numericValue	The value to initialize this FlashValue with.
	*/
	FlashValue(Ogre::Real numericValue);

	/**
	* Creates a FlashValue as a string type.
	*
	* @param	stringValue	The value to initialize this FlashValue with.
	*/
	FlashValue(const char* stringValue);

	/**
	* Creates a FlashValue as a string type.
	*
	* @param	stringValue	The value to initialize this FlashValue with.
	*/
	FlashValue(const wchar_t* stringValue);
	
	/**
	* Creates a FlashValue as a string type.
	*
	* @param	stringValue	The value to initialize this FlashValue with.
	*/
	FlashValue(const Ogre::DisplayString& stringValue);

	/**
	* Retrieves the FlashType of this FlashValue.
	*/
	short getType() const;

	/**
	* Returns whether or not this FlashValue is of a null type.
	*/
	bool isNull() const;

	/**
	* Sets this FlashValue as a null type.
	*/
	void setNull();

	/**
	* If this FlashValue is a boolean type, retrieves the boolean value.
	*/
	bool getBool() const;

	/**
	* If this FlashValue is a number type, retrieves the number value.
	*/
	Ogre::Real getNumber() const;

	/**
	* If this FlashValue is a number type, retrieves the number value interpreted as a color.
	*
	* @note	Color values in ActionScript are generally encoded as a number.
	*/
	Ogre::ColourValue getNumberAsColor() const;

	/**
	* If this FlashValue is a string type, retrieves the string value.
	*/
	const Ogre::DisplayString& getString() const;
};

/**
* Arguments is defined as a vector of FlashValues. Used to communicate with ActionScript functions.
*/
typedef _HikariExport std::vector<FlashValue> Arguments;

/**
* Use the FLASH_VOID macro to represent a null FlashValue type.
*/
#define FLASH_VOID Hikari::FlashValue()

/**
* This helper class can be used to quickly declare variable-length FlashValue arguments inline.
*
* Syntax is: \code Args(x)(x)(x)(x)... \endcode
*/
class _HikariExport Args : public Arguments
{
public:
	Args();

	Args(Args &v);

	explicit Args(const FlashValue& firstArg);

	Args& operator()(const FlashValue& newArg);
};

}

#endif
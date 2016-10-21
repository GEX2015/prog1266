/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

utility class to convert degrees to radius and radius to degrees

*/

#pragma once
#include <cmath>

namespace sf
{
	class Sprite;
	class Text;
}

namespace GEX
{
	void centerOrigin(sf::Sprite& sprite);
	void centerOrigin(sf::Text& text);

	// trig helper function

	const float		M_PI = 3.14159265f;
	inline float	degreesToRadians(float degrees) { return degrees * M_PI / 180.f;}
	inline float	radianToDegrees(float radian) { return radian * 180.f / M_PI; }
	inline float	sin(float degrees) { return std::sin(degreesToRadians(degrees));}
	inline float	cos(float degrees) { return std::cos(degreesToRadians(degrees)); }
}
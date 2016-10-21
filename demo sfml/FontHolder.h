/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This class holde the font that is need in the game

*/

#pragma once

#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include "ResourceIdentifiers.h"

#include <memory>
#include <map>

namespace GEX
{

	class FontHolder
	{

	private:
														FontHolder() {};    // must use getInstance()  
	public:
		static FontHolder&                              getInstance(); // factory method

		void                                            load(FontID id, const std::string& path);
		sf::Font&                                       get(FontID) const;


	private:
		static FontHolder*                              _instance;
		std::map<FontID, std::unique_ptr<sf::Font>>     _fonts;
	};
}

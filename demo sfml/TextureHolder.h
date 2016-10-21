/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

The texture holder is to store the different texture that the game have

*/

#pragma once
#include <memory>
#include <map>
#include "SFML/Graphics.hpp"
#include "ResourceIdentifiers.h"

namespace GEX
{
	
	class TextureHolder
	{
	public:
		static TextureHolder&                              getInstance();

		void                                               load(TextureID id, const std::string& path);
		
		sf::Texture&									   get(TextureID) const;

	private:
		                                                   TextureHolder() {};  // must getInstance() to get it
	private:
		static TextureHolder*                              _instance;

		std::map<TextureID, std::unique_ptr<sf::Texture>>  _textures;
	};
}


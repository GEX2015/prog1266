/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Texture holder class

*/

#include "TextureHolder.h"
#include <cassert>
#include "ResourceIdentifiers.h"

namespace GEX
{

	TextureHolder* TextureHolder::_instance = nullptr;

	TextureHolder& TextureHolder::getInstance()
	{
		if (!TextureHolder::_instance) // lazy instantiation
			TextureHolder::_instance = new TextureHolder();

		return *TextureHolder::_instance;
	}

	void TextureHolder::load(TextureID id, const std::string & path)
	{
		std::unique_ptr<sf::Texture> texture(new sf::Texture);
			if (!texture->loadFromFile(path))
				throw std::runtime_error("Load failed - " + path);

			auto rc = _textures.insert(std::make_pair(id, std::move(texture)));
			if (!rc.second)
				assert(0);
	}

	sf::Texture& TextureHolder::get(TextureID id) const
	{
		auto found = _textures.find(id);
		assert(found != _textures.end());  // find return and iterator to pair in map

		return *found->second;     // de-reference iterator and return pointer by reference
	}
}
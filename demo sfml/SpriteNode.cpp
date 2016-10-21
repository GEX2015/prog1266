/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Spite Node class

*/

#include "SpriteNode.h"

namespace GEX
{

	SpriteNode::SpriteNode(const sf::Texture& texture) :
		_sprite(texture)
	{}

	SpriteNode::SpriteNode(const sf::Texture& texture, sf::IntRect textRect) :
		_sprite(texture, textRect)
	{}

	void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates state) const
	{
		target.draw(_sprite, state);
	}
}
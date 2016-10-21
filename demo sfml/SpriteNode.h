/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This sprite node is for the sprit object in the game.

*/

#pragma once
#include "SceneNode.h"

namespace GEX
{

	class SpriteNode : public SceneNode
	{
	public:
					SpriteNode(const sf::Texture&);
					SpriteNode(const sf::Texture&, sf::IntRect);

	 void			SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;
		
	private:
		sf::Sprite  _sprite;
	};
}



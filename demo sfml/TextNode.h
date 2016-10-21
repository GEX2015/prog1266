/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This text node is a convinience class to have center origin function to center the origine in a sprite.

*/

#pragma once
#include "SceneNode.h"
#include "SFML\Graphics\Text.hpp"
#include <string>

namespace GEX
{
	class TextNode : public SceneNode
	{
	public:
		explicit		TextNode(const std::string& text);
		
		void			setText(const std::string& text);

	private:
		void			drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const override;

	private:
		sf::Text		_text;
	};

}


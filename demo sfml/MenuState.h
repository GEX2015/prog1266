/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

The menu state is where you have the menu play or exit the game with the backgound of two airplaine.

*/

#pragma once
#include "State.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

namespace GEX
{

	class MenuState : public State
	{
	public:
								MenuState(StateStack& stack, Context context);

		virtual void            draw();
		virtual bool            update(sf::Time dt);
		virtual bool            handleEvent(const sf::Event& event);

		void                    updateOptionText();


	private:
		enum OptionNames
		{
			Play,
			Exit,
		};


	private:
		sf::Sprite              _backgroundSprite;

		std::vector<sf::Text>   _options;
		std::size_t             _optionIndex;
	};
}



/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This GexStates classe is like the pause state. You have to push "G" to pause the game. When you press "G" again it start back the game and when you press
backspace it go to the menu.

*/

#pragma once
#include "State.h"

#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\Sprite.hpp"

namespace GEX
{

	class GexState : public State
	{
	public:
								GexState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

	private:
		sf::Sprite				_backgroudSprite;
		sf::Text				_gexText;
		sf::Text				_pauseText;
		sf::Text				_instructionTextBack;
		sf::Text				_instructionTextRetur;
	};

}

//text objects or GUI::Label "game paused", "GEX State", "Press backspace to return to menu", and "Press G to return to game"
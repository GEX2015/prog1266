/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This is the pause state. In the game if you press ESC the game will pause and you will see instructuin on the screen.
ESC to return to the game and backspace to go back to the game.

*/

#pragma once

#include "State.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


namespace GEX
{

	class PauseState : public State
	{
	public:		
							PauseState(StateStack& stack, Context context);

		virtual void        draw();
		virtual bool        update(sf::Time dt);
		virtual bool        handleEvent(const sf::Event& event);


	private:
		sf::Sprite          _backgroundSprite;
		sf::Text            _pausedText;
		sf::Text            _instructionText;
	};

}

/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Pause state class

*/

#include "PauseState.h"
#include "FontHolder.h"
#include "Utility.h"
#include "TextureHolder.h"

#include <SFML\Graphics\/RectangleShape.hpp>
#include <SFML\Graphics\View.hpp>


namespace GEX
{
	PauseState::PauseState(StateStack& stack, Context context) :
		State(stack, context),
		_backgroundSprite(),
		_pausedText(),
		_instructionText()
	{
		sf::Font& font = FontHolder::getInstance().get(FontID::Main);
		sf::Vector2f viewSize = context.window->getView().getSize();

		_pausedText.setFont(font);
		_pausedText.setString("Game Paused");
		_pausedText.setCharacterSize(70);
		centerOrigin(_pausedText);
		_pausedText.setPosition(0.5f * viewSize.x, 0.4f * viewSize.y);

		_instructionText.setFont(font);
		_instructionText.setString("(Press Backspace to return to the main menu)");
		centerOrigin(_instructionText);
		_instructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
	}

	void PauseState::draw()
	{
		sf::RenderWindow& window = *getContext().window;
		window.setView(window.getDefaultView());

		sf::RectangleShape backgroudShape;
		backgroudShape.setFillColor(sf::Color(0, 0, 0, 150));
		backgroudShape.setSize(window.getView().getSize());

		window.draw(backgroudShape);
		window.draw(_pausedText);
		window.draw(_instructionText);
	}

	bool PauseState::update(sf::Time)
	{
		return false;
	}

	bool PauseState::handleEvent(const sf::Event & event)
	{
		if (event.type != sf::Event::KeyPressed)
			return false;

		if (event.key.code == sf::Keyboard::Escape)
		{
			requestStackPop();
		}

		if (event.key.code == sf::Keyboard::BackSpace)
		{
			requestStateClear();
			requestStackPush(StateID::Menu);
		}

		return false;
	}
}

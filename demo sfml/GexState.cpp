/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Gex state class

*/

#include "GexState.h"
#include "TextureHolder.h"
#include "FontHolder.h"

#include <SFML\Graphics\/RectangleShape.hpp>
#include "SFML\Graphics\View.hpp"
#include "Utility.h"


namespace GEX
{
	GexState::GexState(StateStack & stack, Context context) :
		State(stack, context),
		_backgroudSprite(),
		_gexText(),
		_instructionTextRetur(),
		_instructionTextBack(),
		_pauseText()
	{
		// get the main font that we use in the game
		sf::Font& font = FontHolder::getInstance().get(FontID::Main);
		sf::Vector2f viewSize = context.window->getView().getSize();

		// get the background for the gex screen
		_backgroudSprite.setTexture(TextureHolder::getInstance().get(TextureID::GexScreen));
		centerOrigin(_backgroudSprite);
		_backgroudSprite.setColor(sf::Color(255, 255, 255, 100));
		_backgroudSprite.setPosition(0.5f * viewSize.x, 0.5f * viewSize.y);
		

		_gexText.setFont(font);
		_gexText.setString("Gex State");
		_gexText.setCharacterSize(80);
		centerOrigin(_gexText);
		_gexText.setPosition(0.5f * viewSize.x, 0.4f * viewSize.y);

		_pauseText.setFont(font);
		_pauseText.setString("Game Pause");
		_pauseText.setCharacterSize(80);
		centerOrigin(_pauseText);
		_pauseText.setPosition(0.5f * viewSize.x, 0.2f * viewSize.y);

		_instructionTextRetur.setFont(font);
		_instructionTextRetur.setString("Press backspace to return to menu");
		centerOrigin(_instructionTextRetur);
		_instructionTextRetur.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);

		_instructionTextBack.setFont(font);
		_instructionTextBack.setString("G To return to the Game");
		centerOrigin(_instructionTextBack);
		_instructionTextBack.setPosition(0.5f * viewSize.x, 0.7f * viewSize.y);

	}

	void GexState::draw()
	{
		// draw the background the sprite and the to the screen
		sf::RenderWindow& window = *getContext().window;
		window.setView(window.getDefaultView());

		sf::RectangleShape backgroundShape;
		backgroundShape.setFillColor(sf::Color(255, 0, 0, 100));
		backgroundShape.setSize(window.getView().getSize());

		window.draw(backgroundShape);
		window.draw(_backgroudSprite);
		window.draw(_gexText);
		window.draw(_instructionTextRetur);
		window.draw(_instructionTextBack);
		window.draw(_pauseText);
	}

	bool GexState::update(sf::Time dt)
	{
		// return false because is like the pause state the game is in a pause state and should not update
		return false;
	}
	bool GexState::handleEvent(const sf::Event & event)
	{
		// handel the even in the gex state if G is press return to the game
		// if backspace is press return to the menu
		if (event.type != sf::Event::KeyPressed)
			return false;

		if (event.key.code == sf::Keyboard::G)
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
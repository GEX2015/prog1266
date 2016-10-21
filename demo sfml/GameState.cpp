/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Game state class

*/

#include "GameState.h"

namespace GEX
{

	GameState::GameState(StateStack & stack, Context context) :
		State(stack, context),
		_world(*context.window),
		_player(*context.player)
	{}

	void GameState::draw()
	{
		_world.draw();
	}

	bool GameState::update(sf::Time dt)
	{
		_world.update(dt);

		CommandeQueue& commands = _world.getCommandQueue();
		_player.handleRealTimeInput(commands);

		return true;
	}

	bool GameState::handleEvent(const sf::Event & event)
	{
		CommandeQueue& commands = _world.getCommandQueue();
		_player.handleEvent(event, commands);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			requestStackPush(StateID::Pause);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
		{
			requestStackPop();
			requestStackPush(StateID::Menu);
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G)
		{
			requestStackPush(StateID::Gex);
		}
		return true;
	}
}
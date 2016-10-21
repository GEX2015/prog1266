/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This is the application class. This class manage the game loop.

*/

#pragma once
#include "PlayerControl.h"
#include "StateStack.h"

#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "CommandeQueue.h"

namespace GEX
{

	class Application
	{
	public:
								Application();
		void                    run();


	private:
		void                    processInput();
		void                    update(sf::Time dt);
		void                    render();

		void                    updateStatistics(sf::Time dt);
		void                    registerStates();


	private:
		static const sf::Time   TimePerFrame;

		sf::RenderWindow        _window;
		PlayerControl           _player;

		StateStack              _stateStack;

		sf::Text                _statsText;
	};
}

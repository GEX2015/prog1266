/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

CommandeQueue class manage the commande that is pass in the time of a update. it put all the commande make 
by the player and on the update it pass the queue of commande

*/

#pragma once
#include <queue>
#include "Command.h"

namespace GEX
{
	class CommandeQueue
	{
	public:
		void						push(const Command& command);
		Command						pop();
		bool						isEmpty() const;
		
	private:
		std::queue<Command>			_queue;
	};
}



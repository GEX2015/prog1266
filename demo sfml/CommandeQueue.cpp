/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Commande Queue class

*/

#include "CommandeQueue.h"

namespace GEX
{

	void CommandeQueue::push(const Command & command)
	{
		_queue.push(command);
	}

	Command CommandeQueue::pop()
	{
		auto result = _queue.front();
		_queue.pop();
		return result;
	}

	bool CommandeQueue::isEmpty() const
	{
		return _queue.empty();
	}
}



/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Enum for the different state the game could be in

*/

#pragma once

enum class StateID
{
	None,
	Title,
	Menu,
	Game,
	Loading,
	Pause,
	Gex
};
/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

enum to have the type of airplaine

*/

#pragma once

namespace GEX
{
	namespace Category
	{
		enum Type
		{
			None = 0,			 // bit fied operator
			SceneAirLayer		= 1 << 0,
			PlayerAircraft		= 1 << 1,
			AlliedAircraft		= 1 << 2,
			EnnemyAircraft		= 1 << 3,
			Pickup				= 1 << 4,
			AlliedProjectile	= 1 << 5,
			EnemyProjectile		= 1 << 6,

			Airplaine			= PlayerAircraft | AlliedAircraft | EnnemyAircraft,
			Projectile			= AlliedProjectile | EnemyProjectile

		};

	}



}

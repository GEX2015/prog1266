/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

Data Tables class

*/

#include "DataTables.h"
#include "Projectile.h"

namespace GEX
{
	Direction::Direction(float a, float b) : angle(a), distance(b)
	{}

	std::map<Airplaine::Type, AirplainDate> initializeAircraftDate()
	{
		std::map<Airplaine::Type, AirplainDate> data;

		data[Airplaine::Type::Eagle].hitpoint		= 100;
		data[Airplaine::Type::Eagle].speed			= 200.f;
		data[Airplaine::Type::Eagle].fireInterval	= sf::seconds(1);
		data[Airplaine::Type::Eagle].texture		= TextureID::Eagle;
		///////////////////////////////
		data[Airplaine::Type::Raptor].hitpoint		= 20;
		data[Airplaine::Type::Raptor].fireInterval	= sf::Time::Zero;
		data[Airplaine::Type::Raptor].speed			= 80.f;
		data[Airplaine::Type::Raptor].texture		= TextureID::Raptor;

		data[Airplaine::Type::Raptor].direction.push_back(Direction(+80.f, 80.f));
		data[Airplaine::Type::Raptor].direction.push_back(Direction(-80.f, 160.f));
		data[Airplaine::Type::Raptor].direction.push_back(Direction(+80.f, 80.f));
		///////////////////////////////
		data[Airplaine::Type::Avenger].hitpoint		= 40;
		data[Airplaine::Type::Avenger].speed		= 50.f;
		data[Airplaine::Type::Avenger].fireInterval = sf::seconds(2);
		data[Airplaine::Type::Avenger].texture		= TextureID::Avenger;

		data[Airplaine::Type::Avenger].direction.push_back(Direction(+70.f, 150.f));
		data[Airplaine::Type::Avenger].direction.push_back(Direction(0.f, 25.f));
		data[Airplaine::Type::Avenger].direction.push_back(Direction(-70.f, 300));
		data[Airplaine::Type::Avenger].direction.push_back(Direction(0.f, 25.f));
		data[Airplaine::Type::Avenger].direction.push_back(Direction(+70.f, 150.f));
		///////////////////////////////
		return data;
	}

	std::map<Projectile::Type, ProjectileDate> initializeProjectileDate()
	{
		std::map<Projectile::Type, ProjectileDate> data;

		data[Projectile::Type::AlliedBullet].damege		= 10;
		data[Projectile::Type::AlliedBullet].speed		= 300.f;
		data[Projectile::Type::AlliedBullet].texture	= TextureID::Bullet;

		data[Projectile::Type::EnemyBullet].damege		= 10;
		data[Projectile::Type::EnemyBullet].speed		= 300.f;
		data[Projectile::Type::EnemyBullet].texture		= TextureID::Bullet;

		data[Projectile::Type::Missile].damege			= 10;
		data[Projectile::Type::Missile].speed			= 300.f;
		data[Projectile::Type::Missile].texture			= TextureID::Missile;	

		return data;
	}
}
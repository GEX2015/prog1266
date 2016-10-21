/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

airplane class

*/

#include "Projectile.h"
#include "Category.h"
#include <cassert>
#include "TextNode.h"
#include "DataTables.h"
#include "Utility.h"
#include <iostream>
#include <map>



namespace GEX
{

	const std::map<Projectile::Type, ProjectileDate> table = initializeProjectileDate();

	Projectile::Projectile(Type type) :
		Entity(1),
		_type(type),
		_sprite(TextureHolder::getInstance().get(table.at(type).texture))		
	{
		centerOrigin(_sprite);
	}

	unsigned int Projectile::getCategory() const
	{
		if (_type == Type::EnemyBullet)
			return Category::EnemyProjectile;
		else
			return Category::AlliedProjectile;
		
	}


	void Projectile::updateCurrent(sf::Time dt, CommandeQueue& commands)
	{		
		Entity::updateCurrent(dt, commands);
	}
	

	float Projectile::getMaxSpeed() const
	{
		return table.at(_type).speed;
	}

	void Projectile::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_sprite, states);
	}
}




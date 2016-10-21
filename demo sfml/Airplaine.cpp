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

#include "Airplaine.h"
#include "Category.h"
#include <cassert>
#include "TextNode.h"
#include "DataTables.h"
#include "Utility.h"
#include <iostream>
#include <memory>



namespace GEX
{

	const std::map<Airplaine::Type, AirplainDate> table = initializeAircraftDate();

	Airplaine::Airplaine(Type type) :
		Entity(table.at(type).hitpoint),
		_type(type),
		_sprite(TextureHolder::getInstance().get(table.at(type).texture)),
		_directionIndex(0),
		_travelDistance(0),
		_missileAmmo(8)
	{   
		//
		// build fire and launch commande
		//

		_fireCommand.category = Category::SceneAirLayer;
		_fireCommand.action = [this](SceneNode& node, sf::Time dt)
		{
			this->createBullets(node);
		};

		_launchMissileCommande.category = Category::SceneAirLayer;
		_launchMissileCommande.action = [this](SceneNode& node, sf::Time dt)
		{
			this->createProjectile(node, Projectile::Type::Missile, 0.f, 0.5f);
		};

		//
		// build HUD for airplane
		//

		sf::FloatRect bounds = _sprite.getLocalBounds();
		centerOrigin(_sprite);

		std::unique_ptr<TextNode> healthDisplay(new TextNode(std::to_string(getHitPoint()) + " HP"));
		_healthDisplay = healthDisplay.get();
		healthDisplay->setPosition(0.f, 50.f);
		attachChild(std::move(healthDisplay));
	}

	unsigned int Airplaine::getCategory() const
	{
		switch (_type)
		{
		case Type::Eagle:
			return Category::PlayerAircraft;
		case Type::Raptor:
			return Category::AlliedAircraft;
		default:
			assert(0);
			return Category::None;
		};
	}


	void Airplaine::updateCurrent(sf::Time dt, CommandeQueue& commands)
	{
		sf::Vector2f velocity = getVelocity();
		if (velocity.x != 0.f && velocity.y != 0.f)
			setVelocity(velocity / std::sqrt(2.f));

		updateText();
		checkProjectileLaunch(dt, commands);

		movementUpdate(dt);
		Entity::updateCurrent(dt, commands);
	}

	void Airplaine::updateText()
	{
		_healthDisplay->setText(std::to_string(getHitPoint()) + " HP");
		_healthDisplay->setPosition(0.f, 50.f);
		_healthDisplay->setRotation(-getRotation());
	}

	void Airplaine::movementUpdate(sf::Time dt)
	{
		const std::vector<Direction>& directions = table.at(_type).direction;

		if (!directions.empty())  // only auto pilote if I have direction
		{
			float distanceToTravel = directions.at(_directionIndex).distance;
			if (_travelDistance > distanceToTravel)
			{
				_directionIndex = (_directionIndex + 1) % directions.size();
				_travelDistance = 0;
			}

			_travelDistance += getMaxSpeed() * dt.asSeconds();

			float dirAngle = directions.at(_directionIndex).angle + 90.f;
			float vx = getMaxSpeed() * GEX::cos(dirAngle);
			float vy = getMaxSpeed() * GEX::sin(dirAngle);
			setVelocity(vx, vy);
		}
	}

	float Airplaine::getMaxSpeed() const
	{
		return table.at(_type).speed;
	}

	sf::FloatRect Airplaine::getBoundingRect() const
	{
		return getWorldTransform().transformRect(_sprite.getGlobalBounds());
	}

	void Airplaine::fireBullet()
	{
		//std::cout << "Fire" << std::endl;
		// only ships with none zero fire rate fire bullets
		if (table.at(_type).fireInterval != sf::Time::Zero)
			_isFiring = true;
	}

	void Airplaine::launchMissile()
	{
		//std::cout << "Missile" << std::endl;
		if (_missileAmmo > 0)
		{
			_isLaunchingMissile = true;
			--_missileAmmo;
		}
	}

	void Airplaine::checkProjectileLaunch(sf::Time time, CommandeQueue & commands)
	{
		// enemi always fire
		if (!isAllied())
			fireBullet();

		if (_isFiring)
		{
			commands.push(_fireCommand);
  			_isFiring = false;

		}

		if (_isLaunchingMissile)
		{
			commands.push(_launchMissileCommande);
			_isLaunchingMissile = false;
		}
	}

	bool Airplaine::isAllied() const
	{
		return _type == Type::Eagle;
	}

	void Airplaine::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(_sprite, states);
	}

	void Airplaine::createBullets(SceneNode & node) const
	{
		Projectile::Type type = isAllied() ? Projectile::Type::AlliedBullet : Projectile::Type::EnemyBullet;
		createProjectile(node, type, 0, 0.5f);
	}

	void Airplaine::createProjectile(SceneNode & node, Projectile::Type type, float xOffset, float yOffSet) const
	{
		// node is the SceneAirLayer node that the command was target to

		std::unique_ptr<Projectile> projectile(new Projectile(type));

		sf::Vector2f offset(xOffset * _sprite.getGlobalBounds().width, yOffSet * _sprite.getGlobalBounds().height);

		sf::Vector2f velocity(0.f, projectile->getMaxSpeed());

		float sign = isAllied() ? -1.0f : 1.f;
		projectile->setPosition(getWorldPosition() + offset * sign);
		projectile->setVelocity(velocity * sign);

		node.attachChild(std::move(projectile));
	}
}




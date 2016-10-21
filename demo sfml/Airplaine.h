/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

this is the Airplane class it have a enum for the differente type of airplain and function to get different information on the airplaine.


*/
#pragma once

#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "TextureHolder.h"
#include "Command.h"
#include "CommandeQueue.h"
#include "Projectile.h"

namespace GEX
{
	class TextNode;

	class Airplaine : public Entity
	{
	public:
		enum Type
		{
			Eagle,
			Raptor,
			Avenger
		};

	public:
						Airplaine(Type type = Type::Eagle);

		unsigned int	getCategory() const override;
		float			getMaxSpeed() const;
		sf::FloatRect	getBoundingRect() const override;

		void			fireBullet();
		void			launchMissile();
		void			checkProjectileLaunch(sf::Time time, CommandeQueue& commands);
		bool			isAllied() const;
		void			updateText();

	private:
		void			updateCurrent(sf::Time dt, CommandeQueue& commands) override;
		void            movementUpdate(sf::Time dt);
		virtual void    drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;

		void			createBullets(SceneNode& node) const;
		void			createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffSet)const;

	private:
		sf::Sprite      _sprite;
		Type			_type;
		TextNode*		_healthDisplay;
		int				_directionIndex;
		float			_travelDistance;

		Command			_fireCommand;
		Command			_launchMissileCommande;

		std::size_t		_missileAmmo;
		std::size_t		_fireRateLevel;
		std::size_t		_spreadLevel;

		bool			_isFiring;
		bool			_isLaunchingMissile;
		sf::Time		_fireCountDown;
	};
}



/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This Entity class if for all the moving object. Airplaine, bullet, drop inherit from this class

*/

#pragma once
#include "SceneNode.h"
#include "CommandeQueue.h"

namespace GEX
{

	class Entity :	public SceneNode
	{
	public:

						 Entity(int hitpoints = 20);

		void             setVelocity(sf::Vector2f velocity);
		void             setVelocity(float vx, float vy);
		void			 accelerate(sf::Vector2f accelerate);
		void		     accelerate(float vx, float vy);
		sf::Vector2f     getVelocity() const;

		float			 getAngularVelocity() const;
		void			 setAngularVelocity(float av);
		void			 accelerateAngulaVelocity(float av);

		int				 getHitPoint() const;
		void			 repair(int points);
		void			 damage(int points);
		void			 destroy();


	protected:
		virtual void     updateCurrent(sf::Time deltaTime, CommandeQueue& commands) override;
	private:
		
		sf::Vector2f     _velocity;
		float			 _angularVelocity;
		int				 _hitpoints;
		
	};
}

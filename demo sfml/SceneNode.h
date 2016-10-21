/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

This is the scene note class it put every thing in a tree structur. When it update it will go to everything in the scene note.

*/

#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>
#include "Command.h"
#include "Category.h"
#include "CommandeQueue.h"



namespace GEX
{
	class SceneNode : public sf::Transformable, public sf::Drawable
	{
	public:
								typedef std::unique_ptr<SceneNode> Ptr;
	public:
								SceneNode(Category::Type category = Category::None); 
								virtual ~SceneNode();

		// non copyable
								SceneNode(const SceneNode&) = delete;
		SceneNode&				operator=(const SceneNode&) = delete;

		void					attachChild(Ptr child);
		Ptr						detachChild(const SceneNode& node);

		void					onCommande(const Command& command, sf::Time dt);
		virtual unsigned int	getCategory() const;
		sf::Vector2f			getWorldPosition() const;
		sf::Transform			getWorldTransform() const;
		virtual sf::FloatRect	getBoundingRect() const;

		void					update(sf::Time deltaTime, CommandeQueue& commands);
	private:
		
		virtual void			updateCurrent(sf::Time deltaTime, CommandeQueue& commands);
		void					updateChildren(sf::Time deltaTime, CommandeQueue& commands);

		void					draw(sf::RenderTarget& target, sf::RenderStates state) const override final;
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;
		void					drawChildren(sf::RenderTarget& target, sf::RenderStates state) const;
		void					drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		SceneNode*				_parent;
		std::vector<Ptr>		_children;
		Category::Type			_defaultCategory;
	};
}


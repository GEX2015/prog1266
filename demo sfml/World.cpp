/**
@file
@author  Michael Landry	mic_23@hotmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

world class

*/


#include "World.h"
#include "Airplaine.h"
#include "TextureHolder.h"
#include "SpriteNode.h"
#include <math.h>
#include "ResourceIdentifiers.h"
#include <algorithm>
namespace GEX
{

	World::World(sf::RenderWindow& window) :
		_window(window),
		_worldView(window.getDefaultView()),
		_sceneGraph(),
		_sceneLayers(),
		_commandQueue(),
		_worldBounds(0.f, 0.f, _worldView.getSize().x, 2000.f),
		_spawnPosition(_worldView.getSize().x / 2,
		_worldBounds.height - (_worldView.getSize().y / 2.f)),
		_scrollSpeed(-50.0f),
		_playerAircraft(nullptr)
	{
		buildScene();

		// start the view at the bottom of the world
		_worldView.setCenter(_spawnPosition);
	}

	void World::update(sf::Time deltaTime)
	{
		_worldView.move(0.f, _scrollSpeed * deltaTime.asSeconds());
		_playerAircraft->setVelocity(0.f, 0.f);

		while (!_commandQueue.isEmpty())
		{
			_sceneGraph.onCommande(_commandQueue.pop(), deltaTime);
		}

		spawnEnemies();

		// adjust player position
		sf::Vector2f position = _playerAircraft->getPosition();
		sf::Vector2f velocity = _playerAircraft->getVelocity();
		float angularVelocity = _playerAircraft->getRotation();

		if (velocity.x != 0 && velocity.y != 0)
		{
			_playerAircraft->setVelocity(velocity / sqrtf(2.f));
		}

		_playerAircraft->setRotation(angularVelocity);
		// apply movements
		_sceneGraph.update(deltaTime, _commandQueue);
		adapPlayerPosition();
	}

	void World::draw()
	{
		_window.setView(_worldView);
		_window.draw(_sceneGraph);

	}

	void World::adapPlayerPosition()
	{
		sf::FloatRect viewBounds(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
		const float borderDistance = 25.f;

		sf::Vector2f position = _playerAircraft->getPosition();
		position.x = std::max(position.x, viewBounds.left + borderDistance);
		position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
		position.y = std::max(position.y, viewBounds.top + borderDistance);
		position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
		_playerAircraft->setPosition(position);
	}

	CommandeQueue & World::getCommandQueue()
	{
		return _commandQueue;
	}


	void World::buildScene()
	{
		addEnemies();

		// build layer nodes for scene graph
		for (std::size_t i = 0; i < LayerCount; ++i)
		{
			Category::Type category = (i == Air) ? Category::SceneAirLayer : Category::None;
			SceneNode::Ptr layer(new SceneNode(category));
			_sceneLayers[i] = layer.get();
			_sceneGraph.attachChild(std::move(layer));
		}

		// prepare tiled background
		sf::Texture& texture = TextureHolder::getInstance().get(TextureID::Desert);
		sf::IntRect textureRect(_worldBounds);
		texture.setRepeated(true);

		//add background to scneGraph
		std::unique_ptr<SpriteNode> background(new SpriteNode(texture, textureRect));
		background->setPosition(_worldBounds.left, _worldBounds.top);
		_sceneLayers[Backgroud]->attachChild(std::move(background));

		// add planes

		std::unique_ptr<Airplaine> plane(new Airplaine(Airplaine::Type::Eagle));
		plane->setPosition(_spawnPosition);
		plane->setVelocity(0.f, _scrollSpeed);
		_playerAircraft = plane.get();
		_sceneLayers[Air]->attachChild(std::move(plane));
	
	}

	sf::FloatRect World::getViewBounds() const
	{
		return sf::FloatRect(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
	}

	sf::FloatRect World::getBattleFieldBound() const
	{
		sf::FloatRect bounds = getViewBounds();
		bounds.top -= 100;
		bounds.height += 100;
		return bounds;
	}
	void World::spawnEnemies()
	{
		while (!_enemiSpanPoint.empty() && _enemiSpanPoint.back().y > getBattleFieldBound().top)
		{
			auto span = _enemiSpanPoint.back();
			std::unique_ptr<Airplaine> enemy(new Airplaine(span.type));
			enemy->setPosition(span.x, span.y);			
			enemy->setRotation(180);
			_sceneLayers[Air]->attachChild(std::move(enemy));
			_enemiSpanPoint.pop_back();
		}
	}
	void World::addEnemies()
	{
		//add enemy spwan point

		addEnemy(Airplaine::Type::Raptor, -250.f, 200);
		addEnemy(Airplaine::Type::Raptor,  250.f, 200);
		addEnemy(Airplaine::Type::Raptor, -350.f, 400);
		addEnemy(Airplaine::Type::Raptor,  350.f, 400);

		addEnemy(Airplaine::Type::Raptor, -250.f, 800);
		addEnemy(Airplaine::Type::Raptor, 250.f, 800);
		addEnemy(Airplaine::Type::Raptor, -350.f, 900);
		addEnemy(Airplaine::Type::Raptor, 350.f, 900);

		/*addEnemy(Airplaine::Type::Avenger, -250.f, 800);
		addEnemy(Airplaine::Type::Raptor, 250.f, 800);
		addEnemy(Airplaine::Type::Raptor, -350.f, 900);
		addEnemy(Airplaine::Type::Raptor, 350.f, 900);*/

		std::sort(_enemiSpanPoint.begin(), _enemiSpanPoint.end(), [](SpawnPoint lhs, SpawnPoint rhs)
		{
			return lhs.y < rhs.y;
		});
		
	}
	void World::addEnemy(Airplaine::Type type, float relx, float rely)
	{
		addEnemy(SpawnPoint(type, relx, rely));
	}

	void World::addEnemy(SpawnPoint sp)
	{
		sp.x = _spawnPosition.x + sp.x;
		sp.y = _spawnPosition.y - sp.y;
		_enemiSpanPoint.push_back(sp);
	}
}



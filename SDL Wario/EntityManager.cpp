#include "EntityManager.h"

void EntityManager::update()
{
	for (auto& entity : entities) entity->update();
}

void EntityManager::draw()
{
	for (auto& entity : entities) entity->draw();
}

void EntityManager::refresh()
{
}

void EntityManager::addEntity(Entity* player)
{
	std::unique_ptr<Entity> uniqueptr = std::make_unique<Entity>();
	entities.emplace_back((std::move(uniqueptr)));
}

void EntityManager::ereaseEntity(Entity* player)
{

}

Entity* EntityManager::cloneEntity(Entity* Player)
{
	return nullptr;
}


#pragma once
#include <vector>
#include <memory>
#include <Entity.h>

class Entity;

class EntityManager
{
public:
	EntityManager() = default;
	~EntityManager() = default;

	void update();
	void draw();
	void refresh();

	void addEntity(Entity* player);
	void ereaseEntity(Entity* player);
	Entity* cloneEntity(Entity* Player);

private:
	std::vector<std::unique_ptr<Entity>> entities;
};


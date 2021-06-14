#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <string>

class Entity;
class Component; // declaring the classes

using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueComponentID() {
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept { //noexcept if the function were to throw an error it ignores it
	static_assert(std::is_base_of<Component, T>::value, "Type Not base on Component!"); //is basically an asseertion (an assumption) ran at compile time 
	static const ComponentTypeID typeID = getUniqueComponentID();						//is_base_of checks if <base, dervived> "base" is the base class for "Derived"..
	return typeID;
}

constexpr ComponentTypeID MaxEntities = 5000;
constexpr ComponentTypeID Max_Components = 32;

using ComponenetBitSet = std::bitset<Max_Components>;
using ComponentList = std::array<Component*, Max_Components>;

class Component {
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {};
};

class Entity {
private:
	bool isactive = true;
	std::vector<std::unique_ptr<Component>> components;
	Entity() = default;
	ComponentList componentlist;
	ComponenetBitSet componentbitset;
public:
	void update() {
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}

	void draw() {}
	bool isactive const{ return isactive; }
	void destory() { isactive = false; }

	template<typename T> bool hascomponent() const {
		return componentbitset[getComponentTypeID<T>()];
	}

	template <typename T, typename... Targs>
	T& addcomponent(Targs&&... mArgs)
	{
		T* c(new T(std::forward < Targs(mArgs)...));
		c.entity = this;
		std::unique_ptr<Component> uptr{ c };
		components.emplace(std::move(uptr));

		componentlist[getComponentTypeID<T>()] = c;
		componentbitset[getComponentTypeID<T>()] = true;
		c.INIT();
		return c;
	}

	template <typename T> T& getComponent() const {
		auto prt(componentlist[getComponentTypeID<T>()]);
		return *static_cast<T>(ptr);
	}
};

class Manager {
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update() {
		for (auto& e : entities) e->update();
	}

	void draw() {
		for (auto& e : entities) e->draw();
	}

	void refresh() {
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity) {

				return !mEntity->isactive;
			}),
			std::end(entities));
	}

	Entity& addentity() {
		Entity* e = new Entity();
		std::unique_ptr<Entity> uptr{ e };
		entities.emplace_back(std::move(uptr));
		return *e
	}
};
#pragma once
#include <ECS.h>
#include <vector>
#include <memory>
#include <Componenet.h>
#include <Transform.h>

class Entity
{
public:
	Entity() {
		this->addComponent<Transform>(0, 0);
	}
	virtual ~Entity() = default;

	template<typename T, typename... Targs>
	inline T& addComponent(Targs&& ... args) {
		T* comp(new T(std::forward<Targs>(args)...));
		
		
		std::unique_ptr<Component> uptr{ comp };
		components.emplace_back(std::move(uptr));

		if (comp->init())
		{
			complist[getComponentTypeID<T>()] = comp;
			compbitset[getComponentTypeID<T>()] = true;
			comp->entity = this;
			return *comp;
		}
		return *static_cast<T*>(nullptr);



	}

	template<typename T>
	inline T& getComponent() const {
		auto ptr(complist[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

	template<typename T>
	inline bool hascomponent() const {
		return compbitset[getComponentTypeID<T>()];
	}

	inline bool isActive() const{
		return active;
	}

	inline void destroy() {
		active = false;
	}

	inline void draw() {
		for (auto& comp : components)
			comp->draw();
	}

	inline void update() {
		for (auto& comp : components)
			comp->update();
	}

private:
	bool active;
	ComponentList complist;
	ComponenetBitSet compbitset;
	std::vector<std::unique_ptr<Component>> components;
};

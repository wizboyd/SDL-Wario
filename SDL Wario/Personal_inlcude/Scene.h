#pragma once

#include <entt.hpp>
#include <Components.h>

namespace WarioPrimark {

	class Scene
	{
	public:
		Scene();
		~Scene();

		void onUpdate();

		void Init();

		entt::entity CreateEntity();

	private:

		entt::registry m_registry; //registry per scene if i want something to persist i could just copy the item to the new registry

	};





}

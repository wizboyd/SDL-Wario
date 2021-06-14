#pragma once

#include <entt.hpp>
#include <Components.h>
#include <AssetManager.h>
#include <Game.h>

namespace WarioPrimark {

	class Scene
	{
	public:
		Scene(SDL_Renderer* rend)
			:renderer(rend) {};
		~Scene();

		void onUpdate();
		void update();
		void render(SDL_Renderer* renderer);
		void clean();
		void Init();

		entt::entity CreateEntity();

	private:

		entt::registry m_registry; //registry per scene if i want something to persist i could just copy the item to the new registry
		void createMap(entt::entity & Entity);
		SDL_Renderer* renderer;
		

	};





}

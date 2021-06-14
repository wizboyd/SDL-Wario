#include <Scene.h>
#include <iostream>

namespace WarioPrimark {


	Scene::~Scene()
	{

	}


	void Scene::onUpdate()
	{

	}

	void Scene::render(SDL_Renderer* renderer)
	{

	}

	void Scene::Init()
	{
		entt::entity Level = CreateEntity();
		createMap(Level);
		
		
	}

	entt::entity Scene::CreateEntity()
	{
		return m_registry.create();
	}

	void Scene::createMap(entt::entity & Entity)
	{
		 m_registry.emplace<TransformComponent2D>(Entity);
			 m_registry.emplace<TileMapCollider2D>(Entity);
		auto& TMR =	m_registry.emplace<TilemapRenderer>(Entity, renderer);
		auto& mapcomp =	m_registry.emplace<TilemapComponent>(Entity);
		std::cout << "loaded level components" << std::endl;
		mapcomp.Map.loadmap("Mario_staffordshire/test.txt", 32, 32, AssetManager::get(renderer_global)->textures);
		TMR.DrawTileMap(mapcomp.Map);
		std::cout << "loaded map components" << std::endl;
			
	}

}
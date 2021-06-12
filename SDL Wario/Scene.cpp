#include <Scene.h>
#include <iostream>

namespace WarioPrimark {



	Scene::Scene()
	{

	}

	Scene::~Scene()
	{

	}


	void Scene::onUpdate()
	{

	}

	void Scene::Init()
	{
		entt::entity Level = CreateEntity();
		auto &levelTransform = m_registry.emplace<TransformComponent2D>(Level);
		
		
	}

	entt::entity Scene::CreateEntity()
	{
		return m_registry.create();
	}

}
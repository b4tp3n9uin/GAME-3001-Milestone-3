#include "Scene.h"
#include "Game.h"


Scene::Scene()
{
}

Scene::Scene(std::string _name)
{
	name = _name;
}


Scene::~Scene()
{

}

void Scene::Setup()
{

}

void Scene::ReleaseFromScene(GameObject* go)
{
	gameObjects.remove(go);
}

GameObject* Scene::Instantiate(std::string name, const float& x, const float& y, const float& angle)
{
	GameObject* go = game->Instantiate(name, x, y, angle);
	go->scene = this;
	gameObjects.push_back(go);
	return go;
}

GameObject* Scene::Instantiate(GameObject* go, const float& x, const float& y, const float& angle)
{
	game->Instantiate(go, x, y, angle);
	go->scene = this;
	gameObjects.push_back(go);
	return go;
}

GameObject* Scene::Instantiate(std::string name, const Vector2& position, const float& angle)
{
	return Instantiate(name, position.x, position.y, angle);
}

GameObject* Scene::Instantiate(GameObject* go, const Vector2& position, const float& angle)
{
	return Instantiate(go, position.x, position.y, angle);
}

void Scene::Cleanup()
{
	for (GameObject* go : gameObjects)
	{
		game->Destroy(go);
	}
	//gameObjects.clear();
}

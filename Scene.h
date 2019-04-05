#pragma once

#include <iostream>
#include "GameObject.h"
#include "Vector2.h"
class Game;

class Scene
{
public:
	Scene();
	Scene(std::string _name);
	~Scene();

	Game* game;
	std::string name;
	virtual void Setup();
	void Cleanup();
	void ReleaseFromScene(GameObject* go);

	GameObject* Instantiate(std::string name = "", const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(std::string name = "", const Vector2& position = Vector2(0, 0), const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const Vector2& position = Vector2(0, 0), const float& angle = 0);

private:

	std::list<GameObject*> gameObjects;
};


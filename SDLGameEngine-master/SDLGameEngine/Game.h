#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <functional>
#include <map>
#include "GameObject.h"
#include "Input.h"
#include "Transform.h"
#include "Camera.h"
#include "Scene.h"
#include "Physics.h"

typedef GameObject* (*prefab)(Game* game);

class Game
{
public:
	Game();
	virtual ~Game();

	virtual void Awake();
	virtual bool Init();
	virtual void Setup();
	void Update();
	void End();
	static SDL_Window* gWindow;
	//The window renderer
	static SDL_Renderer* gRenderer;

	void SetScene(Scene* scene);

	GameObject* CreateGameObject(std::string name = "", float x = 0, float y = 0, float angle = 0);
	GameObject* Instantiate(std::string name = "", const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(std::string name, const Vector2& position, const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const Vector2& position, const float& angle = 0);

	void Destroy(GameObject* go);

	static int screenWidth;
	static int screenHeight;

	std::map<std::string, std::function<void(GameObject*)>> prefabs;

	void AddPrefab(std::string name, const std::function<void(GameObject*)> &prefabRecipe);
	GameObject* Prefab(std::string name);
	void BulletPrefab(GameObject* go);

	static bool quit;

	Physics* const physics = new Physics();

private:
	void InitializeModules();

	Scene* currentScene = NULL;
	std::list<GameObject*> gameObjects;
	std::list<Module*> modules;
	std::list<GameObject*> objectsToDestroy;

	static float fixedDeltaAccumulator;

	void Awaken(GameObject* go);
};


#pragma once
#include "Game.h"
class DemoGamePjct :
	public Game
{
public:
	DemoGamePjct();
	~DemoGamePjct();
	void Awake();
	void Setup();
	void BackGround();
	void EnemyPrebab(GameObject* enemy);
	void BulletPrebab(GameObject* bullet);
	void WallPrebab(GameObject* wall);
};


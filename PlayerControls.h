#pragma once
#include "Behaviour.h"
#include "Bullet.h"
#include <vector>
using namespace std;

class PlayerControls :
	public Behaviour
{
public:
	PlayerControls();
	~PlayerControls();

	float speed = 100;
	
	void Update();
};

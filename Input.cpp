#include "Input.h"
#include <iostream>
#include "Game.h"
#include <algorithm>

std::list<SDL_Keycode> Input::keyDownEvents = std::list<SDL_Keycode>({});
std::list<SDL_Keycode> Input::keyHoldEvents = std::list<SDL_Keycode>({});
std::list<SDL_Keycode> Input::keyUpEvents = std::list<SDL_Keycode>({});


Input::Input()
{
}


Input::~Input()
{
}

void Input::Update()
{
	/*for (std::list<SDL_Event*>::iterator it = currentEvents.begin(); it != currentEvents.end(); ++it)
	{
		delete *it;
		break;
	}
	currentEvents.clear();*/

	keyDownEvents.clear();
	keyUpEvents.clear();
	//Event handler
	SDL_Event e;
	int i = 0;
	while (SDL_PollEvent(&e))
	{
		i++;
		switch (e.type)
		{
		case SDL_QUIT:
			Game::quit = true;

		case SDL_KEYDOWN:
			if (!Input::GetKey(e.key.keysym.sym))
			{
				keyDownEvents.push_back(e.key.keysym.sym);
				keyHoldEvents.push_back(e.key.keysym.sym);
			}			
			break;

		case SDL_KEYUP:
			keyUpEvents.push_back(e.key.keysym.sym);
			keyHoldEvents.remove(e.key.keysym.sym);
			keyDownEvents.remove(e.key.keysym.sym);
			break;

		default:
			break;
		}
	}
	/*if (i > 0)
	{
		std::cout << "No. of events = " << i << std::endl;
	}*/
}                   

//bool Input::GetMouseButtonDown(SDL_MouseButtonEvent button)
//{
//	for (SDL_Event* e : currentEvents)
//	{
//		if (e->type == SDL_MOUSEBUTTONDOWN && e->button.type == button.type)
//		{
//
//		}
//	}
//	return true;
//}

bool Input::GetKeyDown(SDL_Keycode const &key)
{
	return std::find(keyDownEvents.begin(), keyDownEvents.end(), key) != keyDownEvents.end();
}

bool Input::GetKey(SDL_Keycode const &key)
{
	return std::find(keyHoldEvents.begin(), keyHoldEvents.end(), key) != keyHoldEvents.end();
}

bool Input::GetKeyUp(SDL_Keycode const &key)
{
	return std::find(keyUpEvents.begin(), keyUpEvents.end(), key) != keyUpEvents.end();
}

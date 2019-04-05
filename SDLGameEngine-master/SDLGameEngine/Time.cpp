#include "Time.h"
#include "SDL.h"
#include <iostream>

float Time::timeElapsed = 0;
float Time::deltaTime = 0;
float Time::fixedDeltaTime = 1 / 60.0f;
std::chrono::high_resolution_clock::time_point Time::unscaledTimeElapsed = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> Time::unscaledDeltaTime = std::chrono::high_resolution_clock::now() - std::chrono::high_resolution_clock::now();
float Time::timeScale = 1;

Time::Time()
{
}

Time::~Time()
{
}

void Time::Start()
{
	timeElapsed = 0;
	unscaledTimeElapsed = std::chrono::high_resolution_clock::now();
	deltaTime = 1 / 60.0f;
	Module::Start();
}

void Time::Update()
{
	
	unscaledDeltaTime = std::chrono::high_resolution_clock::now() - unscaledTimeElapsed;
	unscaledTimeElapsed = std::chrono::high_resolution_clock::now();
	if (unscaledDeltaTime.count() < 0.033f)
	{
		deltaTime = (0.9f * deltaTime + 0.1f * unscaledDeltaTime.count()) * (double)timeScale;
	}
	
	timeElapsed += deltaTime;
	Module::Update();
	if (unscaledDeltaTime.count() > 0.04167f)
	{
		std::cout << "unscaled time = " << unscaledDeltaTime.count() << std::endl;
	}
}

float const& Time::TimeElapsed()
{
	return timeElapsed;
}

float const& Time::DeltaTime()
{
	return deltaTime;
}

float const& Time::FixedDeltaTime()
{
	return fixedDeltaTime;
}

void Time::SetFixedDeltaTime(const float& _fixedDeltaTime)
{
	fixedDeltaTime = _fixedDeltaTime;
}

float const& Time::UnscaledTimeElapsed()
{
	return deltaTime;
}

float const& Time::UnscaledDeltaTime()
{
	return unscaledDeltaTime.count();
}

void Time::CleanUp()
{
	Module::CleanUp();
}

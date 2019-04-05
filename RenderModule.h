#pragma once
#include "Module.h"
#include <list>
#include <vector>

class Renderer;
class RenderModule :
	public Module
{
public:
	RenderModule();
	~RenderModule();

	void Start();
	void Update();

	static int numberOfLayers;
	static void AddRenderer(Renderer* renderer);
	static void RemoveRenderer(Renderer* renderer);

private:
	static std::vector<std::list<Renderer*>> renderers; 
};


#include "Renderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "RenderModule.h"

Renderer::Renderer()
{
	RenderModule::AddRenderer(this);
}

Renderer::Renderer(int _layer)
{
	layer = _layer;
	RenderModule::AddRenderer(this);
}

Renderer::~Renderer()
{
}

void Renderer::Cleanup()
{
	RenderModule::RemoveRenderer(this);
}

void Renderer::SetLayer(int _layer)
{
	if (layer != _layer)
	{
		RenderModule::RemoveRenderer(this);
		layer = _layer;
		RenderModule::AddRenderer(this);
	}
}

int Renderer::GetLayer()
{
	return layer;
}

void Renderer::Render()
{

}


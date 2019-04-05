#include "SimpleEventListener.h"

SimpleEventListener::SimpleEventListener(const function &_handler)
{
	handler = _handler;
}

SimpleEventListener::~SimpleEventListener()
{

}

void SimpleEventListener::Handle()
{
	handler();
}

void SimpleEventListener::operator()()
{
	handler();
}

bool SimpleEventListener::IsNotNull()
{
	return handler != nullptr;
}
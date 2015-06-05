#include "Universe.h"

Universe* x_instance = NULL;

Universe::Universe ()
{
	x_EngineState = STARTING;


}

Universe& Universe::GetInstance ()
{
	if ( x_instance == NULL )
	{
		x_instance = new Universe ();
	}
	return *x_instance;
}

bool Universe::Initialize ( unsigned int windowWidth, unsigned int windowHeight, std::string windowTitle, bool antiAliasing, bool fullscreen, bool resizable)
{
	if (x_EngineState == RUNNING) 
	{
		return false;
	}
	x_EngineState = INITIALIZING;

	//TODO : Create a window - Apply proper Settings.

	x_EngineState = RUNNING;
	return true;
}
#include <../Core/Universe.h>

Universe* Universe::x_instance = NULL;

Universe::Universe ()
{
	//-------Start up the Engine-------//
	x_EngineState -> EngineState::STARTING;
	
	//---Begin Low Level Initialization---//
	x_EngineState -> EngineState::INITIALIZING;

	//Engine is ready for the game to take control
	x_EningeState -> EngineState::RUNNING;
}

Universe& Universe::GetInstance ()
{
	if ( x_instance == null )
	{
		x_instance = new Universe();
	}
	return *x_instance;
}
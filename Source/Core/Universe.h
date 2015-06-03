#pragma once

#include <string>
#include <../Utils/EngineState.h>

#define theUniverse Universe::GetInstance()

class Universe
{
public:
	Universe& GetInstance ();

	bool initialize ( 
		unsigned int windowWidth  	= 800,
		unsigned int windowHeight 	= 600, 
		String windowTitle 			= "Last Stand Engine", 
		bool antiAliasing 			= true, 
		bool fullscreen 			= false, 
		bool resizable 				= true 
	);

	
private:
	Universe ();
	static Universe x_instance;

	bool x_AntiAliasing;

	EngineState x_EngineState;
}
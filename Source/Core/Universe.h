#pragma once

#include <string>

#define theUniverse Universe::GetInstance()

class Universe
{
public:
	Universe& GetInstance ();

	bool Initialize ( 
		unsigned int windowWidth  	= 800,
		unsigned int windowHeight 	= 600, 
		std::string windowTitle 	= "Last Stand Engine", 
		bool antiAliasing 			= true, 
		bool fullscreen 			= false, 
		bool resizable 				= true 
	);


private:
	Universe ();
	static Universe* x_instance;

	enum EngineState
	{
		STARTING,
		INITIALIZING,
		RUNNING,
		STOPING,
		UNLOADING
	};

	bool x_AntiAliasing;

	EngineState x_EngineState;
};
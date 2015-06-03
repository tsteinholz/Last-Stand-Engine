#pragma once

#include <string>

class Universe
{
public:
	Universe& getInstance ();

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
}
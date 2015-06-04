#pragma once

#include <string>

/**
* The Singleton Shortcut to get the instance of the Universe
* just by the call of 'TheUniverse'. Super convienient.
**/
#define TheUniverse Universe::GetInstance ();

/**
* This is the mother class of the game. This Class represnts
* the entire game, thus its name "The Universe". Everything
* that goes on in the game will go on in the universe (this
* class). This makes levels and code eaier to manage.
**/
class Universe
{
public:
	/** 
	* This is the method used to get / create the
	* Universe, since there can only be one Universe
	* at a time due to thie Singleton Pattern. This is the 
	* only way to get or create a Universe.
	*
	* @returns The Universe
	**/
	Universe& GetInstance ();

	/**
	* This is the method used to set up the Universe. Since
	* The Singleton Pattern is being used here, this is the
	* closest thing to a constructor. The settings can only
	* inserted in this function one time, to change any 
	* settings a diffrent method must be used.
	*
	* @returns true if successful.
	**/
	bool Initialize ( 
		unsigned int windowWidth  	= 800,
		unsigned int windowHeight 	= 600, 
		std::string windowTitle 	= "Last Stand Engine", 
		bool x_AntiAliasing 		= true, 
		bool fullscreen				= false, 
		bool resizable 				= true 
	);


private:
	/**
	* This is the Constructor for the Universe, it is put
	* in private to reinsure that only one Universe can be 
	* in exsistance at one time. This is the Singleton Pattern
	* and is used on this class very strictly.
	**/
	Universe ();
	
	static Universe* x_instance;

	/**
	* The diffrent modes and states that the Game Engine
	* could possibly be in.
	**/
	enum EngineState
	{
		/**
		* This is the very first state when the engine
		* gets executed, used mainly for set-up. The atcual 
		* window creation is done in the Initialization step.
		**/
		STARTING,
		
		/**
		* At this state the engine is loading the window,
		* all the calls in this state are low-level OpenGL
		* calls to get everything running with the proper 
		* settings and prefrences configured.
		**/
		INITIALIZING,
		
		/**
		* This is the Engine State that it should be in most
		* of the time. In this state the programmer has the
		* most amount of controll over the game and what it
		* doing.
		**/
		RUNNING,

		/**
		* At this state the engine has been told to close
		* one way or another. This is when everything should
		* get to a stopping point because it will soon be
		* removed from memory.
		**/
		STOPING,
	};

	/**
	* This is the current Engine State of the Engine in 
	* real time and will only be modified by the Universe
	* itself.
	**/
	EngineState x_EngineState;
	
	bool x_AntiAliasing;

};
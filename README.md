# Last Stand Engine 

**CURRENTLY UNDER VERY HEAVY DEVELOPMENT!** Last stand engine is a C++ Game Engine targeted for SteamOS (Linux) with Windows/OSX support. The engine will be written in mostly C/C++, compiled with cmake while supporting lua scripting. We expect to have an editor made by v2 of the engine. Everything we have planned is on our [Team Trello Page](https://trello.com/b/t2C62QjU/laststandengine-c), Trello is our planning board for everything. The wikis are being created and will be the main way to learn how to use this engine if interested. At this moment the engine is not at a stable state for game development, the engine is undergowing very heavy development and will have very many major changes made before release of v1. To keep up-to-date with this repo please "star" and "watch" this repository from GitHub as well as check out the [Last Stand Studios Website](http://laststandstudio.com). There you can find our social media and everything else.

# Programming with Last Stand Engine
The current plan for programming language support is a mix of LUA and C++. This means that when implementing this engine, you can create a game using only lua, using only c++, or a mixture of both dependant on the type of file you want to write. We are also going to support JSON files very heavily, and will be the main way to store data. From Settings to Game Objects, JSON will be used to store and edit values. This makes the engine easy to learn from a programming prospective because both JSON and lua are extremely easy to learn, while still being able to get down and dirty with some C++. Other Languages might be supported in the future as well as a possible Level Editor or complete editor to make the game in.

# Get Envolved
This Engine is under very heavy development as mentioned earlier, so we could use as much help as possible. It should not matter what platform you want to develop on because this engine will work on all platforms. We build with cmake, so assuming all linker libraries are set up properly on your system and the cmake file is capable of using them. There should be no problem. To Develop the engine, we mainly use [Clion]() which is a new cross-platform C/C++ IDE from JetBrains. Currently we have applied for free Licences for developers of this project. You can also use and other IDE or Text Editor so long as you continue to use cmake to build and do not depend on others to set up capabilities for you. The next passage will tell you how to build if you want to work from a text editor such as sublime text or atom.

# Building from Source
Unix based systems ... Easy as ctrl-c, ctrl-v.
1. `git clone https://github.com/LastStandStudio/Last-Stand-Engine`
2. `cd Last-Stand-Engine`
3. `mkdir Build`
4. `cd Build`
5. `cmake ..`
6. `make`
7. `./Last-Stand-Engine-Demo`

or one line:
`git clone https://github.com/LastStandStudio/Last-Stand-Engine && cd Last-Stand-Engine && mkdir Build && cd Build && cmake .. && make && ./Last-Stand-Engine-Demo`

# Highlights

* 2D and 3D Support (2D is the main priority as of alpha builds)
* Networking (P2P and Server Connections)
* Cross Platform Support (Will work on any desktop)
* File Manager (Cross Platform Acess to Files)
* Sound Manager (From Music to Sound effects, we got it)
* Joystick / Controller Support (Great for SteamOS)
* Well Managed / Customizable Settings.
* Lua Support
* JSON Support
* And so much more... just look at [Our Team Trello Page](https://trello.com/b/t2C62QjU/laststandengine-c)!
* 


Last Updated [6/14/2015]

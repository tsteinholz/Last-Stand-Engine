# Last Stand Engine

A C++ Game Engine targeted for SteamOS (Linux) with Windows/OSX support. This is just a side-project (open-source and free to use) so don't expect too much. The engine will be written in mostly C/C++, compiled with cmake while supporting lua scripting.

##TODO - UPDATE

# Structure

The executable is meant to be used as a library to make a game with ease without need to worry about low-level programming.

So far this is the Structure of the project:
* Binaries - The execuatables sorted per Operating System 
* Build - The Directory used to build the executables.
* Libraries - The Dependencies for the Engine.
* Source - Where all the actuall engine code is located.

# Features
#### Networking
- Packets
- Packet Registrys
- Custom Handlers

#### Graphics
- OpenGL Rendering
- Base classes
- Layer support
- 3D Capabilities

#### Physics
- WIP

#### Mods
- WIP

#### Sound
- Sound Manager
- Remote (HTTP/Other) Streaming
- Individual Sound Channels (for seperate volumes/priorities)

#### Resources
- Resource Manager
- Repo Downloader

#pragma once

#include <iostream>
#include <string>

class Utils
{
public:
	static void Log ( std::string message );
	static void LogError ( std::string message );
	static std:string GetTime ();
private:
};
#pragma once

#include <string>
#include <sstream>
#include <vector>

static std::vector<std::string> split(const std::string &str, char delim)
{
    std::vector<std::string> elements;
    std::stringstream strStream(str);
    std::string item;

    while(std::getline(strStream,item,delim))
    {
        elements.push_back(item);
    }

    return elements;
}
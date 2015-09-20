#include "Utils/Settings.h"

namespace LSEngine
{
    Settings::Settings(const char *loc)
    {
        // TODO : Test
        std::ifstream t(loc);
        if (!t.good())
        {
            t.close();
            std::ofstream o(loc);
            o << "";
            o.close();
            return;
        }
        std::string str;

        t.seekg(0, std::ios::end);
        str.reserve((unsigned long)t.tellg());
        t.seekg(0, std::ios::beg);

        str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

        t.close();
        x_Settings = json_tokener_parse(str.c_str());
    }

    Settings::~Settings()
    {

    }

    template<typename T>
    void Settings::SetValue(const char* key, T value)
    {

    }

    template<typename T>
    T Settings::GetValue(const char* key)
    {
        return nullptr;
    }

    bool Settings::GetValueAsBool(const char *key)
    {
        return false;
    }

    int Settings::GetValueAsInt(const char *key)
    {
        return 0;
    }
}

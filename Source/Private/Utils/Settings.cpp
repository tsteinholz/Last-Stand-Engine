#include "Utils/Settings.h"

namespace LSEngine
{
    Settings::Settings(const char *loc)
    {

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

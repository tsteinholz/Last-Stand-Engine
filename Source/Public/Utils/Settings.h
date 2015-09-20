#pragma once
#ifndef LSENGINE_UTILS_SETTINGS_H
#define LSENGINE_UTILS_SETTINGS_H

#include <json/json.h>
#include <map>
#include <string>
#include <fstream>
#include <streambuf>

namespace LSEngine
{
    /*
     * The settings class is used for user configuration. There are no set amount of settings and nothing is hard coded
     * which makes this class very expandable as well as portable. If this class is not efficient enough or isn't what
     * you need, then you can still make your own implementation of the same class. And if the expansion is done well
     * enough you could use it interchangeably with this default settings class.
     */
    struct Settings
    {
    public:
        /*
         * @pram char* File location of the settings file, defaults to "Settings.json"
         */
        Settings(const char* loc = "Settings.json");
        ~Settings();

        /*
         * Set a value in the Settings.json, this is done asynchronously so do NOT call this method a lot and never in
         * a loop. It is also worth noting that this function will be doing file i/o. This is a very expensive function
         * and should only be used on occasion and when necessary.
         *
         * @pram char* Name of the key value.
         * @pram T Generic type you want to store.
         */
        template <typename T>
        void SetValue(const char* key, T value);

        /*
         * Get the value of a setting given the key.
         *
         * @pram char* Key value of the value you need.
         *
         * @returns The generic value of the key.
         */
        template <typename T>
        T GetValue(const char* key);

        /*
         * Get the value of a setting given the key.
         *
         * @pram char* Key value of the value you need.
         *
         * @returns The boolean value of the key.
         */
        bool GetValueAsBool(const char* key);

        /*
         * Get the value of a setting given the key.
         *
         * @pram char* Key value of the value you need.
         *
         * @returns The integer value of the key.
         */
        int GetValueAsInt(const char* key);



    protected:
        static json_object* x_Settings;
    };
}

#endif // LSENGINE_UTILS_SETTINGS_H

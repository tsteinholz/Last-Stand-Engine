#ifndef LAST_STAND_ENGINE_LOG_H
#define LAST_STAND_ENGINE_LOG_H

#include <iostream>

class Log {
public:
    Log(const std::string &fName) {
        std::cout << fName << ": ";
    }

    template<class T>
    Log &operator<<(const T &a) {
        std::cout << a;
        return *this;
    }

    ~Log() {
        std::cout << " [eom]" << std::endl;
    }
};

#define LOG Log(__FUNCTION__)

#endif //LAST_STAND_ENGINE_LOG_H
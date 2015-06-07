#include "Utils.h"

namespace LastStandEngine {
    namespace Utils {

        void Utils::Log(const std::string &message) {

        }

        void Utils::LogError(const std::string &message) {
            Log("Error: " + message);
        }
    }
}
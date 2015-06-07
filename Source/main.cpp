#include "main.h"
#include "Utils/Log.h"

int main() {
    Universe universe = TheUniverse;

    universe.Initialize();

    universe.Start();

    LOG << "Hello";

    return 0;
}

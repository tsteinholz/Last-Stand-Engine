#include "main.h"

int main() {
    Universe universe = TheUniverse;

    universe.Initialize();

    universe.Start();

    LOG << "Hello";

    return 0;
}

#pragma once
#ifndef LSENGINE_CORE_GAME_H
#define LSENGINE_CORE_GAME_H

namespace LSEngine
{
    struct Game
    {
    public:
        Game() { }
        virtual ~Game() { }

        virtual void Initalize() { }

        virtual void Execute()
        {

        }

        virtual void Shutdown() { }
    protected:

    };

}

#endif // LSENGINE_CORE_GAME_H

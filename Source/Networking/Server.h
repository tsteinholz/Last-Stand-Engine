#ifndef SOMNIA_ENGINE_SERVER_H
#define SOMNIA_ENGINE_SERVER_H

#define SERVER LSEngine::Networking::Server::GetInstance()

namespace LSEngine
{
    namespace Networking
    {
        class Server
        {
        public:

            static Server& GetInstance();

            bool InitializeServer();

        private:
            Server();
            ~Server();
        };
    }
}


#endif

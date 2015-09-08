#include <Networking/Server.h>

namespace LSEngine {
    namespace Networking {
        Server& Server::GetInstance() {
            static Server instance;
            return instance;
        }

        Server::Server(){

        }

        Server::~Server() {

        }
    }
}
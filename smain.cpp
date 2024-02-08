#include "server.hpp"

int main()
{
    Server myserver("0.0.0.0",0000);
    myserver.SeverInit();
    myserver.ServerAccept();

    while(1)
    {
        myserver.ServerRecieve();
        myserver.ServerExecuteCommand();
    }

    return 0;
}

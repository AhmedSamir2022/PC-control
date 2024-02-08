#include <functional>
#include <future>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <string>

class Command{
    public:
    Command();
    ~Command();

    protected:
    std::map<std::string,void(Command::*)()> commands = {
                                                        {"terminal\r\n",&Command::CommandTerminal},
                                                        {"google\r\n",&Command::CommandGoogle},
                                                        {"youtube\r\n",&Command::CommandYoutube},
                                                        {"calculator\r\n",&Command::CommandCalculator},
                                                        {"suspend\r\n",&Command::CommandSuspend}
                                                        };
    private:
    void CommandTerminal();
    void CommandGoogle();
    void CommandYoutube();
    void CommandCalculator();
    void CommandSuspend();
    
};

class Server : public Command{
    public:
	Server(std::string ipAddress,int portNumber);
	~Server();
	void SeverInit();
    void ServerAccept();
    void ServerRecieve();
    void ServerSend(std::string message);
    void ServerExecuteCommand();
    void ServerClose();

    private:
	int serverListeningSocket;
	int serverConnectionSocket;
    int pendingNum = 1;
    sockaddr_in serverAddress;
    std::string ipAddress; 
    int portNumber;

    std::string dataBuffer = "";
    char str[100] = {0};
      
};
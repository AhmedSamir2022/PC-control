#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "server.hpp"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
 #include <cstring>

Server::Server(std::string ipAddress,int portNumber):ipAddress(ipAddress),portNumber(portNumber){}
Server::~Server()
{
	ServerClose();
}

void Server::SeverInit(){
	/*Creating the server socket*/
	serverListeningSocket = socket(AF_INET,SOCK_STREAM,0);
	if(serverListeningSocket == -1){
		std::cerr<<"Creating failed, sorry!"<<std::endl;
		exit(EXIT_FAILURE);
	}
	/*Specifying the server address "ip address & port number" */
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(portNumber);
	char* ip = ipAddress.data();
	inet_pton(AF_INET, ip, &serverAddress.sin_addr);
	
	/*Binding the address to the socket*/
	if(bind(serverListeningSocket,reinterpret_cast<sockaddr*>(&serverAddress),sizeof(serverAddress)) == -1){
		std::cerr<<"Binding failed, sorry!"<<std::endl;
		close(serverListeningSocket);
		exit(EXIT_FAILURE);
	}
	/*listening to clients*/
	if(listen(serverListeningSocket,pendingNum) == -1){
		std::cerr<<"Listening failed, sorry!"<<std::endl;
		close(serverListeningSocket);
		exit(EXIT_FAILURE);
	}

}

void Server::ServerAccept(){
	/*Accepting a Client Connection*/
	serverConnectionSocket = accept(serverListeningSocket,nullptr,nullptr);
	if(serverConnectionSocket == -1){
		std::cerr<<"Accepting failed, sorry!"<<std::endl;
		close(serverListeningSocket);
		exit(EXIT_FAILURE);
	}
}

void Server::ServerRecieve(){
	dataBuffer = "";
	memset(str, 0, sizeof(str));
	if(recv(serverConnectionSocket,str,sizeof(str),0) == -1){
		std::cerr<<"Recieving failed, sorry!"<<std::endl;
		close(serverListeningSocket);
		exit(EXIT_FAILURE);
	}
	else{
		dataBuffer = str;
		std::cout<<"Message from client: "<<dataBuffer<<std::endl;
		std::transform(dataBuffer.begin(), dataBuffer.end(), dataBuffer.begin(), ::tolower);
	}
}

void Server::ServerSend(std::string message){
	char* str = message.data();

    if(send(serverConnectionSocket,str,strlen(str),0) == -1){
		std::cerr<<"Sending failed, sorry!"<<std::endl;
	}	
}

void Server::ServerExecuteCommand(){
	if(fork() == 0)
	{
		(this->*commands[dataBuffer])();
	}
}

void Server::ServerClose(){
	close(serverListeningSocket);
}

Command::Command(){}
Command::~Command(){}
void Command::CommandTerminal(){
	execlp("gnome-terminal","gnome-terminal", nullptr);
}
void Command::CommandGoogle(){
	execlp("google-chrome","google-chrome", nullptr);
}
void Command::CommandYoutube(){
	system("google-chrome https://www.youtube.com");
}
void Command::CommandCalculator(){
	execlp("gnome-calculator","gnome-calculator", nullptr);
}
void Command::CommandSuspend(){
	system("sudo pm-suspend");
}
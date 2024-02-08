# PC-control
This is a simple C++ server application that listens for incoming connections from clients and executes predefined commands based on client requests.This enables me to perform various actions remotely, enhancing the flexibility and accessibility of my PC. It can be used as a starting point for creating your own server applications.
# Features
-Accepting connections from Clients.

-Recieving Commands from the Client.

-Executing predefined commands based on client requests, you can add your own commands by modifying the server code.
# Prerequisites
-C++ Compiler (g++).

-linux Operating System (ubuntu).

-Knowlege of C++,STL,OOP.

-Basic Knowledge of Socket programming.
# Getting Started
1. Put your device ip address and port number in smain.cpp file:

![WhatsApp Image 2024-02-08 at 9 06 49 PM](https://github.com/AhmedSamir2022/PC-control/assets/115807184/969bcc5d-509e-4b7a-8d7f-95c77921ddc1)

2. Clone this repository to your local machine:

```
https://github.com/AhmedSamir2022/PC-control.git
```
3. Compile your server program:

```
g++ smain.cpp server.cpp -o s.out
```
# Usage
1. start your server
```
./s.out
```
-The server intiates & starts to listen for client.

-Try to Connect to the server with a Client.

-Send one of the predefined commands with Client to Server (terminal,calculator,google,youtube,suspend..).

# Setup Client
Use Tcp Udp Server & Client App..[Downloud](https://play.google.com/store/apps/details?id=tcpudpserverclient.steffenrvs.tcpudpserverclient&pcampaignid=web_share&pli=1&raii=tcpudpserverclient.steffenrvs.tcpudpserverclient&raboi=CAE%3D&rasi=4822299910820656511&rapt=AEjHL4NXXWRRFC-pBBf7QN3Z57KFHLF2rqiMm7vLv5tyTZ5drYogeQicX9BrcM-QV0_IJd1YK6ePhKtGpkh1ctK6skH9F54BleojvmuW0YYXTC7FDgbvmqE)

# Acknowledgments
This project was created as a learning exercise in socket programming and C++.

Feel free to customize and expand upon this project to further develop your skills and create more advanced server-client applications.

# References
[Socket Programming in C++](https://www.geeksforgeeks.org/socket-programming-in-cpp/)

[Socket Programming in C++](https://marketsplash.com/tutorials/cpp/cplusplus-scoket/)

[How To Open a Port on Linux](https://www.digitalocean.com/community/tutorials/opening-a-port-on-linux)

[How to get your Linux IP address](https://www.ionos.com/digitalguide/hosting/technical-matters/get-linux-ip-address/)

[fork()](https://www.geeksforgeeks.org/fork-system-call/)

[execlp()](https://www.javatpoint.com/execlp-function-in-c)

[system()](https://www.quora.com/How-do-I-use-terminal-commands-in-C++)





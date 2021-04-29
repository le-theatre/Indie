/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Server
*/

#include <iostream>
#include <exception>
#include "Server.hpp"

Server::Server()
{     
    // Creating socket file descriptor
    _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (_sockfd < 0) {
        throw std::runtime_error(std::string("Error: creating socket server"));
    }
      
    memset(&_servaddr, 0, sizeof(_servaddr));
      
    // Filling server information
    _servaddr.sin_family    = AF_INET; // IPv4
    _servaddr.sin_addr.s_addr = INADDR_ANY;
    _servaddr.sin_port = htons(50001);
      
    // Bind the socket with the server address
    if (bind(_sockfd, (const struct sockaddr *)&_servaddr, sizeof(_servaddr)) < 0) {
        throw std::runtime_error(std::string("Error: Binding server"));
    }
}

Server::~Server()
{
}

void Server::recvdata()
{
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(sockaddr_in);
    int n;
    char buffer[1024] = {0};
    
    memset(&cliaddr, 0, sizeof(cliaddr));
    len = sizeof(cliaddr);
    n = recvfrom(_sockfd, (char *)buffer, 1024, 
                MSG_WAITALL, (struct sockaddr *) &cliaddr,
                &len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);

    sendto(_sockfd, (const char *)"hello", strlen("hello"), 
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
            len);
}
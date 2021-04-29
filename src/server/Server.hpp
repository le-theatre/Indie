/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class Server {
    public:
        Server();
        ~Server();
        void recvdata();
        int _sockfd;

    protected:
    private:
        struct sockaddr_in _servaddr;
};

#endif /* !SERVER_HPP_ */

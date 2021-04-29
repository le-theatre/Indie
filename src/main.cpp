/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** main
*/

#include "Server.hpp"

int main([[maybe_unused]]int ac, [[maybe_unused]]char **argv, [[maybe_unused]]char **envp)
{
    Server server;

    while (1) {
        server.recvdata();
    }
}
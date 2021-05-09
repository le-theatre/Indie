/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include "IndieServer.hpp"

int main(int argc, char const *argv[])
{
    try {
        return indieserv::IndieServer(argc, argv).Run();
    } catch (...) {
        return 84;
    }
}

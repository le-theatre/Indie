/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include "IndieStudioServer.hpp"

int main(int argc, char const *argv[])
{
    try {
        return IndieStudioServer(argc, argv).start();
    } catch (...) {
        return 84;
    }
}

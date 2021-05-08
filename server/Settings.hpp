/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Settings
*/

#pragma once

namespace server {

template <typename TClient, typename TPacket>
struct Settings {
    using Client = TClient;
    using Packet = TPacket;
};

}

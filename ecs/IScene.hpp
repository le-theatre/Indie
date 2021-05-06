/*
** EPITECH PROJECT, 2021
** indie
** File description:
** IScene
*/

#pragma once

class IScene {
public:
    virtual void onStart() = 0;
    virtual void onStop() = 0;
    virtual void onPause() = 0;
    virtual void onResume() = 0;
    virtual void handleEvent() = 0;
    virtual void fixedUpdate() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void shadowUpdate(float deltaTime) = 0;
    virtual void shadowFixedUpdate() = 0;
    virtual void updateSystems() = 0;
};

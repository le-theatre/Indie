cmake_minimum_required(VERSION 3.16)
project(indie)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(ecs)

add_executable(indie
        ecs/AScene.h
        ecs/IComponent.hpp
        ecs/IEntity.hpp
        ecs/IScene.hpp
        ecs/ISystem.hpp)

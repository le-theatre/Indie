cmake_minimum_required(VERSION 3.16)
project(indie)

set(CMAKE_CXX_STANDARD 17)

add_library(ecs STATIC
        ECS.hpp
        ECS.cpp
        Entity.hpp
        Entity.cpp
        ISystem.hpp
        Scene.hpp
        World.hpp

        components/Transform.hpp)

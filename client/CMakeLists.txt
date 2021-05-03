cmake_minimum_required(VERSION 3.16)
project(indie)

set(CMAKE_CXX_STANDARD 17)

add_executable(client
    main.cpp

    components/Renderer.hpp

    systems/Draw.hpp)

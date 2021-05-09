###############################################################################
# Misc                                                                        #
###############################################################################
cmake_minimum_required(VERSION 3.16)
project(indie CXX)
set(CMAKE_CXX_STANDARD 17)

###############################################################################
# Indie ECS Source                                                            #
###############################################################################
add_library(lib_indie_ecs STATIC
    components/Transform.hpp
    Components.hpp
    ECS.hpp
    EntityManager.hpp
    IScene.hpp
    Scene.hpp
    Settings.hpp
    Signature.hpp
    System.hpp
    TypeList.hpp
)

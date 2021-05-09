###############################################################################
# Misc                                                                        #
###############################################################################
cmake_minimum_required(VERSION 3.16)
project(indie)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-I../deps)

###############################################################################
# Indie Server Source                                                         #
###############################################################################
add_library(lib_indie_server STATIC
    Server.cpp
    Server.hpp
    Settings.hpp
    Logger.cpp
    Logger.hpp
    IndieStudioServer.hpp
    IndieStudioServer.cpp
    Config.hpp)

###############################################################################
# Executable                                                                  #
###############################################################################
add_executable(indie_server main.cpp)
target_link_libraries(indie_server PUBLIC lib_indie_server)
target_link_libraries(indie_server PUBLIC lib_clilib)

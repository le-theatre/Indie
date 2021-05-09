###############################################################################
# Misc                                                                        #
###############################################################################
cmake_minimum_required(VERSION 3.16)
project(indie)
set(CMAKE_CXX_STANDARD 17)
include_directories(../deps)

###############################################################################
# Indie Server Source                                                         #
###############################################################################
add_library(lib_indie_server STATIC
    IndieServer.hpp
    IndieServer.cpp
    ArgumentsParser.cpp
    ArgumentsParser.hpp

    server/Config.hpp
    server/Engine.cpp
    server/Engine.hpp
)

###############################################################################
# Executable                                                                  #
###############################################################################
add_executable(indie_server main.cpp)
target_link_libraries(indie_server PUBLIC lib_indie_server)
target_link_libraries(indie_server PUBLIC lib_cli)
target_link_libraries(indie_server PUBLIC lib_log)

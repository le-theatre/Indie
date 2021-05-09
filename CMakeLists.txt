###############################################################################
# Misc                                                                        #
###############################################################################
cmake_minimum_required(VERSION 3.16)
project(indie)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra)

###############################################################################
# Subdirectories                                                              #
###############################################################################
# add_subdirectory(ecs)
# add_subdirectory(client)
add_subdirectory(deps/clilib)
add_subdirectory(server)

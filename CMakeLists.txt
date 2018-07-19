cmake_minimum_required(VERSION 3.10)
project(Limite C)

set(CMAKE_C_STANDARD 99)

add_executable(Limite card.c card.h welcome.c welcome.h server.c server.h server_utils.c server_utils.h)
cmake_minimum_required(VERSION 3.13)
project(ElectronicVoting)

set(CMAKE_CXX_STANDARD 98)

add_executable(ElectronicVoting main.cpp Structures/Voter.h Structures/Voter.cpp Functions/Parser.h Functions/Parser.cpp)
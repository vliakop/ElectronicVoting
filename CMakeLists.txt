cmake_minimum_required(VERSION 3.13)
project(ElectronicVoting)

set(CMAKE_CXX_STANDARD 98)

add_executable(ElectronicVoting main.cpp Structures/Voter.h Structures/Voter.cpp Functions/Parser.h Functions/Parser.cpp Functions/Validator.h Functions/Validator.cpp Functions/Assigner.h Functions/Assigner.cpp Functions/Implementator.h Functions/Implementator.cpp Files/FileOperations.h Files/FileOperations.cpp Structures/BloomFilter.h Structures/BloomFilter.cpp Structures/RBTree.h Structures/RBTree.cpp Structures/IdentityCardList.h Structures/IdentityCardList.cpp Structures/PCList.h Structures/PCList.cpp Structures/Fenrir.h Structures/Fenrir.cpp elections.cpp runelection.cpp)
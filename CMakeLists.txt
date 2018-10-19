cmake_minimum_required(VERSION 3.8)
project(Homework3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BST.cpp BST.h AVL.cpp AVL.h AVLCommands.cxx BSTSanityCheck.cxx CreateData.cxx)
add_executable(Homework3 ${SOURCE_FILES})
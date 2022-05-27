cmake_minimum_required(VERSION 3.22)
project(Steganography)

set(CMAKE_CXX_STANDARD 20)

add_executable(steganography src/main.cpp src/flags.cpp src/flags.h src/info.cpp src/help.cpp src/encrypt.cpp src/decrypt.cpp src/check.cpp src/info.h)

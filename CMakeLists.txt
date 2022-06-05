cmake_minimum_required(VERSION 3.22)
project(Steganography)

set(CMAKE_CXX_STANDARD 20)

add_executable(steganography src/files/main.cpp src/files/flags.cpp src/headers/flags.h src/files/info.cpp src/files/help.cpp src/files/encrypt.cpp src/files/decrypt.cpp src/files/check.cpp src/headers/info.h src/headers/check.h)

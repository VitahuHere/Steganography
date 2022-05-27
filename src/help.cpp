//
// Created by vumir on 26.05.2022.
//
#include <iostream>

void help() {
    const char *helpMessage = R"(Picture stenography program.
    Encode and decode messages hidden inside images.
    - Author: Cong Minh Vu 11c s25026
    - Supports .png, .bmp

    Usage: stenography.exe [OPTION]...
    Example: stenography.exe -e C:\image.png "Lorem ipsum"
    Basic commands:
     -i, --info PATH                shows information about file and whether it's supported or not
     -e, --encrypt PATH MESSAGE     encrypts data into the the file specified in PATH. MESSAGE must by in quotes (" ").
                                    Checks if file extension is supported, then writes  MESSAGE into image.
     -d, --decrypt PATH             decrypts encoded data from an image. File extension must be supported.
     -c, --check PATH MESSAGE       checks if message can be successfully encrypted into the image.
     -h, --help                     general help
)";
    std::cout << helpMessage << std::endl;
}
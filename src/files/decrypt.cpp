//
// Created by vumir on 26.05.2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include "../headers/info.h"


void decryptForBmp(const std::string &path);

void decryptForPpm(const std::string &path);


void decrypt(const std::string &path) {
    if (!isSupported(path)) {
        std::cout << "File extension is not supported." << std::endl;
        return;
    }
    if (getFileExtension(path) == ".bmp") {
        decryptForBmp(path);
    } else if (getFileExtension(path) == ".ppm") {
        decryptForPpm(path);
    }
}


void decryptForBmp(const std::string &path) {
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(10, std::ios::beg);
    int offset;
    file.read((char *) &offset, sizeof(offset));
    file.seekg(offset, std::ios::beg);
    for (int i = 0; i < 8; i++) {

    }
    file.close();
}

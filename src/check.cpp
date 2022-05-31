//
// Created by vumir on 26.05.2022.
//

#include <string>
#include <fstream>
#include <iostream>


void check(const std::string &path, const std::string &message) {
    std::fstream file(path, std::ios::binary | std::ios::in);
    for (int i = 0; i < 20; ++i) {
        std::cout << i << ": " << file.get() << " ";
    }
    file.close();
}
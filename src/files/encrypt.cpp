//
// Created by vumir on 26.05.2022.
//

#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include "../headers/check.h"
#include "../headers/info.h"

void encryptForBmp(const std::string &path, std::string message);

void encryptForPpm(const std::string &path, std::string message);

std::array<unsigned char, 8> toBinary(unsigned char decimal);


void encrypt(const std::string &path, const std::string &message) {
    if (!isSupported(path)) {
        std::cout << "File extension is not supported." << std::endl;
        return;
    }
    if (!check(path, message) && std::to_string(message.size()).size() > 4) {
        std::cout << "Message is too long. Cannot store" << std::endl;
        return;
    }
    if (getFileExtension(path) == ".bmp") {
        encryptForBmp(path, message);
    } else if (getFileExtension(path) == ".ppm") {
        encryptForPpm(path, message);
    }
}


void encryptForBmp(const std::string &path, std::string message) {
    while(std::to_string(message.size()).size() < 4) {
        message.insert(0, "0");
    }
    std::cout<<message<<std::endl;
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(10, std::ios::beg);
    int offset;
    file.read((char *) &offset, sizeof(offset));
    file.seekg(offset, std::ios::beg);
    for (char c : message){
        std::array<unsigned char, 8> binary = toBinary(c);
        for (int i = 0; i < 8; i++) {
            unsigned char ch = file.get();
            std::cout<<(int)ch<<std::endl;
            ch ^= (-binary[i] ^ ch) & 0x01;
            std::cout<<(int)ch<<std::endl;
            file.seekp(-1, std::ios::cur);
            file<<ch;
        }
    }
    file.close();
}


void encryptForPpm(const std::string &path, std::string message) {
    message = std::to_string(message.size()) + message;
}


std::array<unsigned char, 8> toBinary(unsigned char decimal) {
    std::array<unsigned char, 8> binary{};
    for (int i = 7; i >= 0; i--) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    return binary;
}
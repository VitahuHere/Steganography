//
// Created by vumir on 26.05.2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <cmath>
#include "../headers/info.h"
#include "../headers/encrypt.h"


void decryptForBmp(const std::string &path);

void decryptForPpm(const std::string &path);

int binaryToDecimal(std::array<unsigned char, 8> binary);

int getMessageLengthBmp(std::fstream &file);

void getMessage(std::fstream &file, int length);


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
    /**
     * @brief Decrypts message from bmp file
     * @param path - path to file
     * @return
     * @details
     * Function determines message length and offsets its pointer by length * 8.
     * Then decrypts message. Using simple principal:
     *     - for each character in message, we get 8 bits from file
     *     - for each byte we take LSB and store it in array
     *     - we convert array to decimal and read it as char
     *     - we add char to final string
     */
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(getCharOffsetBmp(path), std::ios::beg);
    int length = getMessageLengthBmp(file);
    file.seekg(getCharOffsetBmp(path) + MAX_MESSAGE_SIZE * 8, std::ios::beg);
    getMessage(file, length);
    file.close();
}


void decryptForPpm(const std::string &path) {
    /**
     * @brief Decrypts message from ppm file
     * @param path - path to file
     * @return
     * @details
     * Function determines message length and offsets its pointer by length * 8.
     * Then decrypts message. Using simple principal:
     *     - for each character in message, we get 8 bits from file
     *     - for each byte we take LSB and store it in array
     *     - we convert array to decimal and read it as char
     *     - we add char to final string
     */
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    offsetPpm(file);
    int length = getMessageLengthBmp(file);
    getMessage(file, length);
    file.close();
}


int binaryToDecimal(std::array<unsigned char, 8> binary) {
    int decimal = 0;

    for (int i = 0; i < 8; i++) {
        decimal += (int) (binary[i] * pow(2, 7 - i));
    }

    return decimal;
}


int getCharOffsetBmp(const std::string &path) {
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(10, std::ios::beg);
    int offset;
    file.read((char *) &offset, sizeof(offset));
    file.close();
    return offset;
}


int getMessageLengthBmp(std::fstream &file) {
    std::array<unsigned char, MAX_MESSAGE_SIZE * 8> size{};
    for (int i = 0; i < MAX_MESSAGE_SIZE * 8; i++) {
        size[i] = file.get() & 1U;
    }
    std::string charLength;
    std::array<unsigned char, 8> binary{};
    for (int i = 0; i < MAX_MESSAGE_SIZE * 8; ++i) {
        binary[i % 8] = size[i];
        if ((i + 1) % 8 == 0) {
            charLength += char(binaryToDecimal(binary));
        }
    }
    return std::stoi(charLength);
}


void getMessage(std::fstream &file, int length) {
    std::string message;
    for (int i = 0; i < length; i++) {
        std::array<unsigned char, 8> binary{};
        for (int j = 0; j < 8; j++) {
            unsigned char ch = file.get();
            binary[j] = ch & 0x01;
        }
        message += (char) binaryToDecimal(binary);
    }
    std::cout<<message<<std::endl;
}
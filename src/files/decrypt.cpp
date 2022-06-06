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

int getMessageLength(std::fstream &file);

void getMessage(std::fstream &file, int length);


void decrypt(const std::string &path) {
    /**
     * @brief Decrypts file
     * @param path - Path to file
     * @return void
     * @details
     * Checks if file is supported by program, then checks if having sufficient permissions to read file.
     * Calls appropriate function to decrypt file.
     */
    if (!isSupported(path)) {
        std::cout << "File extension is not supported." << std::endl;
        return;
    }
    if (!getFilePermissions(path).at("others_read")) {
        std::cout << "File is not readable." << std::endl;
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
    int length = getMessageLength(file);
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
    int length = getMessageLength(file);
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
    /**
     * @brief Gets offset of message in bmp file
     * @param path - path to file
     * @return offset of message in file
     * @details
     * Function gets offset of message in file.
     * Move pointer to 10th byte in header file to read next 4 bytes which is offset of pixel array.
     *
     */
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(10, std::ios::beg);
    int offset;
    file.read((char *) &offset, sizeof(offset));
    file.close();
    return offset;
}


int getMessageLength(std::fstream &file) {
    /**
     * @brief Gets length of message in file
     * @param file - file stream
     * @return length of message in file
     * @details
     * Function gets length of message in file.
     * Given file stream is already opened and in the right position, for each character in message,
     * we get 8 bits from file. For each byte we take LSB and store it in array.
     * We convert array to decimal and read it as char.
     * We add char to final string.
     * We return length of message.
     */
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
    /**
     * @brief Gets message from file
     * @param file - file stream
     * @param length - length of message
     * @return void
     * @details
     * Function gets message from file.
     * Given file stream is already opened and in the right position, for each character in message,
     * we get 8 bits from file. For each byte we take LSB and store it in array.
     * We convert array to decimal and read it as char.
     * We add char to final string.
     * We print message.
     */
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
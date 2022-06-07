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

std::string fillMessage(const std::string &message);

void writeToFile(std::fstream &file, const std::string &message);

void offsetPpm(std::fstream &file);


/**
     * @brief Encrypts message to file with given path
     * @param path - path to file
     * @param message - message to encrypt
     * @return void
     * @details
     * Function determines if file extension is supported, then if message can fit inside the file
     * and finally calls appropriate function if no error is raised.
     */
void encrypt(const std::string &path, const std::string &message) {
    if (!isSupported(path)) {
        std::cout << "File extension is not supported." << std::endl;
        return;
    }
    if (std::to_string(message.size()).size() > MAX_MESSAGE_SIZE) {
        std::cout << "Message is too long. Cannot store" << std::endl;
        return;
    }
    if (!getFilePermissions(path).at("others_write")) {
        std::cout << "File is not writable." << std::endl;
        return;
    }
    if (getFileExtension(path) == ".bmp") {
        encryptForBmp(path, message);
    } else if (getFileExtension(path) == ".ppm") {
        encryptForPpm(path, message);
    }
}


/**
     * @brief Encrypts message to bmp file
     * @param path - path to file
     * @param message - message to encrypt
     * @return void
     * @details
     * Function determines message length and fills the message length string with '0' to fill up the MAX_MESSAGE_SIZE.
     * Then encrypts message. Using simple principal:
     *    - for each character in message, we get binary value of a character then convert it to array of 8 bits
     *    - for each bit in array we take 1 byte from file and change LSB to be exactly the same as bit in array
     *    - we write new byte to file
     *    - repeat until all bits are written
     */
void encryptForBmp(const std::string &path, std::string message) {
    message = fillMessage(message);
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(getCharOffsetBmp(path), std::ios::beg);
    writeToFile(file, message);
    file.close();
    std::cout<<"Message encrypted."<<std::endl;
}


/**
     * @brief Encrypts message to ppm file
     * @param path - path to file
     * @param message - message to encrypt
     * @return void
     * @details
     * Function determines message length and fills the message length string with '0' to fill up the MAX_MESSAGE_SIZE.
     * Then encrypts message. Using simple principal:
     *   - for each character in message, we get binary value of a character then convert it to array of 8 bits
     *   - for each bit in array we take 1 byte from file and change LSB to be exactly the same as bit in array
     *   - we write new byte to file
     *   - repeat until all bits are written
     */
void encryptForPpm(const std::string &path, std::string message) {
    message = fillMessage(message);
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    offsetPpm(file);
    writeToFile(file, message);
    file.close();
    std::cout<<"Message encrypted."<<std::endl;
}


/**
     * @brief Offsets ppm file to the right position
     * @param file - file stream
     * @return void
     * @details
     * Function offsets file stream to the right position.
     * It skips header of the file and stops at the first byte of the pixel array.
     * It is used to make sure that we are writing to the pixel array position in ppm file and not damage the header.
     */
void offsetPpm(std::fstream &file) {
    std::string c;
    std::getline(file, c);
    do {
        std::getline(file, c);
    } while (c[0] == '#');
    std::getline(file, c);
}


/**
     * @brief Writes message to file
     * @param file - file stream
     * @param message - message to write
     * @return void
     * @details
     * Function writes message to file.
     * It iterates through message and for each character in message, we get binary value of a character then convert it to array of 8 bits.
     * For each bit in array we take 1 byte from file and change LSB to be exactly the same as bit in array.
     * We write new byte to file.
     * We repeat until all bits are written.
     */
void writeToFile(std::fstream &file, const std::string &message) {
    for (char c: message) {
        std::array<unsigned char, 8> binary = toBinary(c);
        for (int i = 0; i < 8; i++) {
            unsigned char ch = file.get();
            ch ^= (-binary[i] ^ ch) & 0x01;
            file.seekp(-1, std::ios::cur);
            file << ch;
        }
    }
}


std::array<unsigned char, 8> toBinary(unsigned char decimal) {
    std::array<unsigned char, 8> binary{};
    for (int i = 7; i >= 0; i--) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    return binary;
}


std::string fillMessage(const std::string &message) {
    std::string size = std::to_string(message.size());
    while (size.size() < MAX_MESSAGE_SIZE) {
        size.insert(0, "0");
    }
    return (size + message);
}
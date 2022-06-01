//
// Created by vumir on 26.05.2022.
//

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "info.h"


void checkForBmp(const std::string &path, const std::string &message);

std::size_t getBytesNeeded(const std::string &message);

int getBytesNeededForChar(char c);


void check(const std::string &path, const std::string &message) {
    /**
     * @brief Checks if file can store specified data
     * @param path Path to file
     * @param message Message to be encoded in file
     * @details
     * Checks if file is supported by program, then checks if having sufficient permissions to write to file.
     * If file is supported and having sufficient permissions, checks if file can store specified message.
     */
    if (!isSupported(path)) {
        std::cout << "File " << path << " is not supported" << std::endl;
        return;
    }
    if (!getFilePermissions(path).at("others_read")) {
        std::cout << "File " << path << " is not readable" << std::endl;
        return;
    }
    if (getFileExtension(path) == ".bmp") {
        checkForBmp(path, message);
    }
}


void checkForBmp(const std::string &path, const std::string &message) {
    /**
     * @brief Checks if file can store specified data
     * @param path Path to file
     * @param message Message to be encoded in file
     * @details
     * Gets data dimensions from file header and calculates available pixels.
     * If available pixels are less than needed, prints error message.
     */
    std::fstream p(path, std::ios::in | std::ios::binary);
    unsigned char width[4];
    p.seekg(18, std::ios::beg);
    p.read((char *) width, 4);
    unsigned char height[4];
    p.seekg(22, std::ios::beg);
    p.read((char *) height, 4);

    int width_ = width[0] + width[1] * 256 + width[2] * 256 * 256 + width[3] * 256 * 256 * 256;
    int height_ = height[0] + height[1] * 256 + height[2] * 256 * 256 + height[3] * 256 * 256 * 256;

    int pixel_count = width_ * height_;
    if (pixel_count >= getBytesNeeded(message)) {
        std::cout << "File " << path << " can store message" << std::endl;
    } else {
        std::cout << "File " << path << " can not store message" << std::endl;
    }
    p.close();
}


std::size_t getBytesNeeded(const std::string &message) {
    /**
     * @brief Calculates how many bytes are needed to store specified message
     * @param message Message to be encoded in file
     * @return Number of bytes needed to store specified message
     */
    std::size_t bytes_needed = 0;
    for (char c: message) {
        bytes_needed += getBytesNeededForChar(c);
    }
    return bytes_needed;
}


int getBytesNeededForChar(char c) {
    unsigned char decimal = c, binary = 0, remainder, product = 1, runs = 0;
    while (decimal != 0) {
        runs++;
        remainder = decimal % 2;
        binary = binary + (remainder * product);
        decimal = decimal / 2;
        product *= 10;
    }
    return runs;
}
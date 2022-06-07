//
// Created by vumir on 26.05.2022.
//

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "../headers/info.h"


bool checkForBmp(const std::string &path, const std::string &message, bool output);

bool checkForPpm(const std::string &path, const std::string &message, bool output);


/**
     * @brief Checks if file can store specified data
     * @param path Path to file
     * @param message Message to be encoded in file
     * @details
     * Checks if file is supported by program, then checks if having sufficient permissions to write to file.
     * If file is supported and having sufficient permissions, checks if file can store specified message.
     */
bool check(const std::string &path, const std::string &message, bool output = false) {
    if (!isSupported(path)) {
        std::cout << "File " << path << " is not supported" << std::endl;
        return false;
    }
    if (!getFilePermissions(path).at("others_read")) {
        std::cout << "File " << path << " is not readable" << std::endl;
        return false;
    }
    if (!getFilePermissions(path).at("others_write")) {
        std::cout << "File " << path << " is not writable" << std::endl;
        return false;
    }
    bool canStore = false;
    if (getFileExtension(path) == ".bmp") {
        canStore = checkForBmp(path, message, output);
    } else if (getFileExtension(path) == ".ppm") {
        canStore = checkForPpm(path, message, output);
    }
    return canStore;
}


/**
     * @brief Checks if file can store specified data
     * @param path - Path to file
     * @param message - Message to be encoded in file
     * @details
     * Gets image dimensions from file header and calculates available pixels.
     * Then checks if message can be encoded in file.
     * It does so by calculating number of characters and multiplying it by 8, then comparing it to number of available pixels.
     */
bool checkForBmp(const std::string &path, const std::string &message, bool output) {
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
    if (output) {
        if (pixel_count >= message.size() * 8 + MAX_MESSAGE_SIZE * 8) {
            std::cout << "File " << path << " can store message" << std::endl;
        } else {
            std::cout << "File " << path << " can not store message" << std::endl;
        }
    }
    p.close();
    return pixel_count >= message.size() * 8;
}


/**
     * @brief Checks if file can store specified data
     * @param path Path to file
     * @param message Message to be encoded in file
     * @details
     * Gets image dimensions from file header and calculates available pixels.
     * Then checks if message can be encoded in file.
     * It does so by calculating number of characters and multiplying it by 8, then comparing it to number of available pixels.
     */
bool checkForPpm(const std::string &path, const std::string &message, bool output = true) {
    std::fstream p(path, std::ios::in | std::ios::binary);
    std::string c;
    std::getline(p, c);
    do {
        std::getline(p, c);
    } while (c[0] == '#');
    std::string width_str;
    std::string height_str;
    for (char ch: c) {
        if (ch == '\n' || ch == '\r' || ch == ' ') {
            break;
        }
        width_str += ch;
    }
    int width_ = std::stoi(c);
    for (char ch: c) {
        if (ch == '\n' || ch == '\r' || ch == ' ') {
            break;
        }
        height_str += ch;
    }
    int height_ = std::stoi(c);
    int pixel_count = width_ * height_;
    if (output) {
        if (pixel_count >= message.size() * 8 + MAX_MESSAGE_SIZE * 8) {
            std::cout << "File " << path << " can store message" << std::endl;
        } else {
            std::cout << "File " << path << " can not store message" << std::endl;
        }
    }
    p.close();
    return pixel_count >= message.size() * 8;
}

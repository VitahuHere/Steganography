//
// Created by vumir on 26.05.2022.
//
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "flags.h"

long long getFileSize(const std::string &path) {
    std::ifstream file(path);
    file.seekg(0, std::ios::end);
    return file.tellg();
}

std::string getFileModifiedTime(const std::string &path) {
    struct stat attr{};
    stat(path.c_str(), &attr);
    return ctime(&attr.st_mtime);
}

void printFileInfo(const std::string &path, const std::string &ext) {
    std::cout << "File extension " + ext << std::endl;
    std::cout << "File path " + path << std::endl;
    std::cout << "File size " << std::to_string(getFileSize(path)) << " bytes" << std::endl;
    std::cout << "File last modified " << getFileModifiedTime(path) << std::endl;
}

void info(const std::string &path) {
    /**
     * @brief Prints information about the file.
     * @param path Path to the file.
     * @return void
     * @details
     * This function prints information about the file.
     * It checks if the file extension is supported.
     * If the file extension is supported, it prints the file extension, the file size and the file modification date.
     */
    for (const std::string &ext: getSupportedExtensions()) {
        std::regex rgx(".*" + ext + "$");
        if (std::regex_match(path, rgx)) {
            printFileInfo(path, ext);
            return;
        }
    }
    std::cout << "File extension is not supported." << std::endl;
}


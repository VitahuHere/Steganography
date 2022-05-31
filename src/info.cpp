//
// Created by vumir on 26.05.2022.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <chrono>
#include "flags.h"

namespace fs = std::filesystem;

bool isSupported(const std::string &path);
void printFileInfo(const std::string &path, const std::string &ext);
std::string getFileExtension(const std::string &path);
std::string getLastModified(const std::string &path);


void info(const std::string &path) {
    /**
     * @brief Prints information about the file.
     * @param path Path to the file.
     * @return void
     * @details
     * This function prints information about the file.
     * It checks if the file extension is supported.
     * If the file extension is supported, it prints the file extension, the file size and the file modification date.
     * If the file extension is not supported, prints an error message.
     */
    if (isSupported(path)){
        printFileInfo(path, getFileExtension(path));
    }
    else {
        std::cout << "File extension is not supported." << std::endl;
    }
}


void printFileInfo(const std::string &path, const std::string &ext) {
    std::cout << "File name: " << fs::path(path).filename() << std::endl;
    std::cout << "File extension " + ext << std::endl;
    std::cout << "File path " + path << std::endl;
    std::cout << "File size " << std::to_string(fs::file_size(path)) << " bytes" << std::endl;
    std::cout << "File modification date " << getLastModified(path) << std::endl;
}


std::string getFileExtension(const std::string &path) {
    fs::path p(path);
    return p.extension().string();
}


bool isSupported(const std::string &path){
    fs::path p(path);
    return std::ranges::any_of(getSupportedExtensions(), [&](const std::string &ext) {
        return p.extension() == ext;
    });
}


std::string getLastModified(const std::string &path) {
    auto last_write_time = fs::last_write_time(path);
    std::time_t last_write_time_t = std::chrono::system_clock::to_time_t(std::chrono::file_clock::to_sys(last_write_time));
    return std::asctime(std::localtime(&last_write_time_t));
}
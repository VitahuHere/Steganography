//
// Created by vumir on 26.05.2022.
//
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sys/stat.h>
#include "flags.h"


bool isSupported(const std::string &path);
long long getFileSize(const std::string &path);
std::string getFileModifiedTime(const std::string &path);
void printFileInfo(const std::string &path, const std::string &ext);
std::string getFileExtension(const std::string &path);


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


std::string getFileExtension(const std::string &path) {
    /**
     * @brief Gets the file extension.
     * @param path Path to the file.
     * @return File extension.
     * @details
     * This function gets the file extension.
     * It returns the file extension.
     */
    std::string extension;
    std::string::size_type i = path.rfind('.', path.length());
    if (i != std::string::npos) {
        extension = path.substr(i + 1, path.length() - i);
    }
    return extension;
}


bool isSupported(const std::string &path){
    /**
     * @brief Checks if the file extension is supported.
     * @param path Path to the file.
     * @return True if the file extension is supported, false otherwise.
     * @details
     * This function checks if the file extension is supported.
     * It takes the file extension from constant array specified in getSupportedExtensions().
     * It returns true if the file extension is supported, false otherwise.
     */
    return std::ranges::any_of(getSupportedExtensions(), [&path](const std::string &ext) {
        return std::regex_match(path, std::regex(".*\\." + ext + "$"));
    });
}


void printFileInfo(const std::string &path, const std::string &ext) {
    std::cout << "File extension " + ext << std::endl;
    std::cout << "File path " + path << std::endl;
    std::cout << "File size " << std::to_string(getFileSize(path)) << " bytes" << std::endl;
    std::cout << "File last modified " << getFileModifiedTime(path) << std::endl;
}


long long getFileSize(const std::string &path) {
    /**
     * @brief Gets the file size.
     * @param path Path to the file.
     * @return File size.
     * @details
     * This function gets the file size.
     * Instead of looping through the file, it uses built in seekg() function.
     */
    std::ifstream file(path);
    file.seekg(0, std::ios::end);
    return file.tellg();
}


std::string getFileModifiedTime(const std::string &path) {
    struct stat attr{};
    stat(path.c_str(), &attr);
    return ctime(&attr.st_mtime);
}

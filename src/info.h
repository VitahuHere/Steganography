//
// Created by vumir on 27.05.2022.
//

#ifndef STEGANOGRAPHY_INFO_H
#define STEGANOGRAPHY_INFO_H

#include <string>

bool isSupported(const std::string &path);
long long getFileSize(const std::string &path);
std::string getFileModifiedTime(const std::string &path);
void printFileInfo(const std::string &path, const std::string &ext);
std::string getFileExtension(const std::string &path);

#endif //STEGANOGRAPHY_INFO_H

// Author: Cong Minh Vu
// Written on 26.05.2022

#ifndef STEGANOGRAPHY_INFO_H
#define STEGANOGRAPHY_INFO_H

#include <string>
#include <map>

#define MAX_MESSAGE_SIZE 4

bool isSupported(const std::string &path);

void printFileInfo(const std::string &path);

std::string getFileExtension(const std::string &path);

std::string getLastModified(const std::string &path);

std::map<std::string, bool> getFilePermissions(const std::string &path);

int getCharOffsetBmp(const std::string &path);

#endif //STEGANOGRAPHY_INFO_H

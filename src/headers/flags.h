//
// Created by vumir on 26.04.2022.
//

#ifndef LEARNING_FLAGS_H
#define LEARNING_FLAGS_H

#include <map>

void help();

void info(const std::string &path);

void encrypt(const std::string &path, const std::string &message);

void decrypt();

void check(const std::string &path, const std::string &message, bool output = false);

std::map<std::string, std::array<int, 2> > commandLineFlags();

std::string invalidArgument(const std::string &arg);

std::string tooManyArguments(const std::string &arg);

std::string missingArguments(const std::string &arg);

std::vector<std::string> getSupportedExtensions();

#endif //LEARNING_FLAGS_H

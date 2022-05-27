//
// Created by vumir on 26.04.2022.
//

#ifndef LEARNING_FLAGS_H
#define LEARNING_FLAGS_H

void help();

void info(const std::string& path);

void encrypt();

void decrypt();

void check(const std::string& path, const std::string& message);

std::map<std::string, std::array<int, 2> > commandLineFlags();

std::string invalidArgument(const std::string& arg);

std::string tooManyArguments(const std::string& arg);

std::string missingArguments(const std::string& arg);

std::vector<std::string> getSupportedExtensions();
#endif //LEARNING_FLAGS_H

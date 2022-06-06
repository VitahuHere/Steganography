#include <bits/stdc++.h>
#include <iostream>
#include "../headers/flags.h"

int main(int argc, const char *argv[]) {
    /**
     * @brief Main function.
     * @param argc Number of arguments.
     * @param argv Array of arguments.
     * @return void
     * @details
     * This function is the main function.
     * Depending on specified flag, it calls the appropriate function and passes appropriate parameters.
     * If there are no arguments or flags, it prints general help.
     * If there are too little or too many arguments, it prints an error message.
     */
    if (argc == 1) {
        help();
        return 0;
    }
    int command = commandLineFlags()[argv[1]][0];
    int maxArguments = commandLineFlags()[argv[1]][1];
    if (argc != maxArguments && maxArguments != 0) {
        std::cout << (argc > maxArguments ? tooManyArguments(argv[1]) : missingArguments(argv[1])) << std::endl;
        return 1;
    }
    switch (command) {
        case 1:
            help();
            break;
        case 2:
            info(argv[2]);
            break;
        case 3:
            encrypt(argv[2], argv[3]);
            break;
        case 4:
            decrypt(argv[2]);
            break;
        case 5:
            check(argv[2], argv[3], true);
            break;
        default:
            std::cout<<invalidArgument(argv[1]);
            break;
    }
    return 0;
}
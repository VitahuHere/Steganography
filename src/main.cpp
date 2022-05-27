#include <bits/stdc++.h>
#include <iostream>
#include "flags.h"

int main(int argc, const char *argv[]) {
    if(argc == 1) {
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
        case 1: help();
            break;
        case 2: info(argv[2]);
            break;
        case 3: encrypt();
            break;
        case 4: decrypt();
            break;
        case 5: check();
            break;
        default: invalidArgument(argv[1]);
            break;
    }
    return 0;
}
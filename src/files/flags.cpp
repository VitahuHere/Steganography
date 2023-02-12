// Author: Cong Minh Vu
// Written on 26.05.2022

#include <string>
#include <array>
#include <vector>
#include <map>


// mapping command to switch number and expected number of arguments
std::map<std::string, std::array<int, 2> > commandLineFlags() {
    return std::map<std::string, std::array<int, 2> >{
            {"--help",    {1, 2}},
            {"-h",        {1, 2}},
            {"--info",    {2, 3}},
            {"-i",        {2, 3}},
            {"--encrypt", {3, 4}},
            {"-e",        {3, 4}},
            {"--decrypt", {4, 3}},
            {"-d",        {4, 3}},
            {"--check",   {5, 4}},
            {"-c",        {5, 4}}
    };
}

std::vector<std::string> getSupportedExtensions() {
    return std::vector<std::string>{".ppm", ".bmp"};
}

std::string invalidArgument(const std::string &arg) {
    return "Invalid argument: '" + arg + "' try --help for more information.";
}

std::string tooManyArguments(const std::string &arg) {
    return "Too many arguments. Try --help for more information.";
}

std::string missingArguments(const std::string &arg) {
    return "Missing argument for '" + arg + "'. Try --help for more information.";
}
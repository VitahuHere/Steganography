//
// Created by vumir on 26.05.2022.
//

#include <string>
#include "CImg/CImg.h"
using namespace cimg_library;

void check(const std::string& path, const std::string& message){
    CImg<unsigned char> img(100, 100, 1, 3);
    img.display();
}
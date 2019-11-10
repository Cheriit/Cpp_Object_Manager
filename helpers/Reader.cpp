//
// Created by cherit on 11/10/19.
//

#include <iostream>
#include "Reader.h"

float Reader::readNum(std::ifstream& InputFile){
    std::string tmp;
    getline(InputFile, tmp);
    if (tmp.empty()) return 0;
    try {
        return stof(tmp);
    }catch( const std::invalid_argument& ia) {
        return 0;
    }
}

void Reader::readString(std::string text, std::string& target) {
    std::string tmp;
    std::cout << text << ":" << std::endl;
    getline(std::cin, tmp);
    if(!tmp.empty()) target = tmp;
}

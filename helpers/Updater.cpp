//
// Created by cherit on 11/10/19.
//

#include "Updater.h"
#include <limits>

void Updater::updateStr(std::string text, std::string& target) {
    std::string tmp;
    std::cout << text << ":(" << target << ")" << std::endl;
    getline(std::cin, tmp);
    if(!tmp.empty()) target = tmp;
}

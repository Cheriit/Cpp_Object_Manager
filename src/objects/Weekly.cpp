//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Weekly.h"

Weekly::Weekly(): Magazine() {}
Weekly::Weekly(ifstream& InputFile): Magazine(InputFile) {}

void Weekly::putDetails(ofstream& OutputFile) {
    OutputFile << "WEEKLY" << endl;
    OutputFile << this->publish_day << endl;
    OutputFile << this->getBarCode() << endl;
}

void Weekly::printDetails() {
    cout << "Weekly: " << endl;
    cout << "\tPublish day: " << this->publish_day << endl;
    cout << "\tBarcode: " << this->getBarCode() << endl;
}

void Weekly::update() {
}
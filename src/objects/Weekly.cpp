//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Weekly.h"

Weekly::Weekly(): Magazine() {}
Weekly::Weekly(ifstream& InputFile): Magazine(InputFile) {}

WeekDay Weekly::getPublishDay() { return this->publish_day; }
string Weekly::getBarCode() { return  this->bar_code; }

void Weekly::setPublishDay(WeekDay day) { this->day = day; }
void Weekly::setBarCode(string bar_code) { this->bar_code = bar_code; }

void Weekly::putDetails(ofstream& OutputFile) {
    OutputFile << "WEEKLY" << endl;
    OutputFile << this->publish_day << endl;
    OutputFile << this->bar_code << endl;
}

void Weekly::printDetails() {
    cout << "Weekly: " << endl;
    cout << "\tPublish day: " << this->publish_day << endl;
    cout << "\tBarcode: " << this->bar_code << endl;
}

void Weekly::update() {
}
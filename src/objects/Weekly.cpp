//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Weekly.h"
#include "../../helpers/Reader.h"
#include "../../helpers/Updater.h"

Weekly::Weekly() {
    string tmp;
    int tmp2;

    cout << "\t\tWEEKLY" << endl;
    cout << "Barcode:" << endl;
    getline(cin, tmp);
    this->setBarCode(tmp);
    Reader::readNum<int>("Publish day (1 - Monday, ..., 7 - Sunday)", tmp2);
    this->setPublishDay(tmp2);
}
Weekly::Weekly(ifstream& InputFile) {
    this->setPublishDay((Reader::readNum(InputFile)));
    string tmp;
    getline(InputFile, tmp);
    this->setBarCode(tmp);

}
void Weekly::setPublishDay(int day) {
    if(day>7)
        this->publish_day = static_cast<WeekDay>(0);
    else
        this->publish_day = static_cast<WeekDay >(day);
}

string Weekly::getPublishDay() {
    switch(this->publish_day)
    {
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wensday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        case 7:
            return "Sunday";
        default:
            return "Unspecified";
    }
}

void Weekly::putDetails(ofstream& OutputFile) {
    OutputFile << this->publish_day << endl;
    OutputFile << this->getBarCode() << endl;
}

void Weekly::printDetails() {
    cout << "Weekly: " << endl;
    cout << "\tPublish day: " << this->getPublishDay() << endl;
    cout << "\tBarcode: " << this->getBarCode() << endl;
}

void Weekly::update() {
    std::string tmp;
    std::cout << "Barcode:(" << this->getBarCode() << ")" << std::endl;
    getline(std::cin, tmp);
    if(!tmp.empty()) this->setBarCode(tmp);
    int tmp2 = this->publish_day;
    Updater::updateNum("Publish week day type: 1- Monday, ..., 7- Sunday", tmp2);
    this->setPublishDay(tmp2);
}


//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Monthly.h"
#include "../../helpers/Reader.h"
#include "../../helpers/Updater.h"

Monthly::Monthly(): Magazine() {
    string tmp;
    cout << "\t\tMONTHLY" << endl;
    cout << "Barcode:" << endl;
    getline(cin, tmp);
    this->setBarCode(tmp);
    Reader::readNum<int>("Publish day", this->publish_day);
}
Monthly::Monthly(ifstream& InputFile): Magazine(InputFile) {
    string tmp;
    getline(InputFile, tmp);
    this->setBarCode(tmp);
    this->publish_day = Reader::readNum(InputFile);
}

void Monthly::putDetails(ofstream& OutputFile) {
    Magazine::putDetails(OutputFile);
    OutputFile << this->getPublishDay() << endl;
    OutputFile << this->getBarCode() << endl;
}

void Monthly::printDetails() {
    Magazine::printDetails();
    cout << "Monthly: " << endl;
    cout << "\tPublish day: " << this->getPublishDay() << endl;
    cout << "\tBarcode: " << this->getBarCode() << endl;
}

void Monthly::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" Number " << this->magazine_number << " published by " << this->publisher_name << endl;
    cout << "\t Published at " << this->getPublishDay()  << endl;
}

void Monthly::update() {
    Magazine::update();
    std::string tmp;
    std::cout << "Barcode:(" << this->getBarCode() << ")" << std::endl;
    getline(std::cin, tmp);
    if(!tmp.empty()) this->setBarCode(tmp);
    Updater::updateNum<int>("Publish day", this->publish_day);

}



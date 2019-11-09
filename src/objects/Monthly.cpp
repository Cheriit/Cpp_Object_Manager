//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Monthly.h"

Monthly::Monthly(): Magazine() {
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string tmp;
    int tmp2;

    cout << "\t\tMONTHLY" << endl;
    cout << "Barcode:" << endl;
    getline(cin, tmp);
    this->setBarCode(tmp);
    cout << "Publish day:" << endl;
    cin >> tmp2;
    this->setPublishDay(tmp2);
}
Monthly::Monthly(ifstream& InputFile): Magazine(InputFile) {
    string tmp;
    getline(InputFile, tmp);
    this->setBarCode(tmp);
    this->publish_day = Object_interface::readNum(InputFile);
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

std::ostream &operator<<(std::ostream &output, const Monthly& monthly) {
    output << monthly.name << endl;
    return  output;
}

void Monthly::update() {
    Magazine::update();
    std::string tmp;
    std::cout << "Barcode:(" << this->getBarCode() << ")" << std::endl;
    getline(std::cin, tmp);
    if(!tmp.empty()) this->setBarCode(tmp);
    Object_interface::updateNum<int>("Publish day", this->publish_day);

}


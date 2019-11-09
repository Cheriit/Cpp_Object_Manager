//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Monthly.h"

Monthly::Monthly(): Magazine() {}
Monthly::Monthly(ifstream& InputFile): Magazine(InputFile) {}

void Monthly::putDetails(ofstream& OutputFile) {
    OutputFile << "MONTHLY" << endl;
    OutputFile << this->getPublishDay() << endl;
    OutputFile << this->getBarCode() << endl;
    Magazine::putDetails(OutputFile);
}

void Monthly::printDetails() {
    cout << "Monthly: " << endl;
    cout << "\tPublish day: " << this->getPublishDay() << endl;
    cout << "\tBarcode: " << this->getBarCode() << endl;
    Magazine::printDetails();
}

void Monthly::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" Number " << this->magazine_number << " published by " << this->publisher_name << endl;
    cout << "\t Published at " << this->getPublishDay()  << endl;
}

std::ostream &operator<<(std::ostream &output, const Monthly& monthly) {
    output << monthly.name << endl;
    output << "\t\"" << monthly.title <<"\" Number " << monthly.magazine_number << " published by " << monthly.publisher_name << endl;
    output << "\t Published at " << monthly.publish_day  << endl;
    return  output;
}

void Monthly::update() {
    Magazine::update();
}


//
// Created by cherit on 11/3/19.
//

#include "Monthly.h"

Monthly::Monthly(): Magazine() {}
Monthly::Monthly(ifstream& InputFile): Magazine(InputFile) {}

int Monthly::getPublishDay() { return this->publish_day; }
string Monthly::getBarCode() { return  this->bar_code; }

void Monthly::setPublishDay(int day) { this->day = day; }
void Monthly::setBarCode(string bar_code) { this->bar_code = bar_code; }

void Monthly::putDetails(ofstream& OutputFile) {
    OutputFile << "MONTHLY" << endl;
    OutputFile << this->publish_day << endl;
    OutputFile << this->bar_code << endl;
    Magazine::putDetails(OutputFile);
}

void Monthly::printDetails() {
    cout << "Monthly: " << endl;
    cout << "\tPublish day: " << this->publish_day << endl;
    cout << "\tBarcode: " << this->bar_code << endl;
    Magazine::printDetails();
}

void Monthly::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" Number " << this->magazine_number << " published by " << this->publisher_name << endl;
    cout << "\t Published at " << this->publish_day  << endl;
}

std::ostream& Monthly::operator<<(std::ostream& output, const Monthly& weekly) {
    output << this->getName() << endl;
    output << "\t\"" << this->getTitle() <<"\" Number " << this->getManagzineNumber() << " published by " << this->getPublisherName() << endl;
    output << "\t Published at " << this->getPublishDay()  << endl;
    return  output;
}

void Monthly::update() {
    Magazine::update();
}
//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Daily.h"
#include "../../helpers/Updater.h"
#include "../../helpers/Reader.h"

Daily::Daily() {
    cout << "\t\tDAILY" << endl;
    Reader::readString("Printing hour", this->printing_hour);
    Reader::readString("Publishment area", this->publishment_area);
}
Daily::Daily(ifstream& InputFile) {
    getline(InputFile, this->printing_hour);
    getline(InputFile, this->publishment_area);
}

string Daily::getPrintingHour() { return this->printing_hour; }
string Daily::getPublishmentArea() { return this->publishment_area; }

void Daily::setPrintingHour(const string&) { this->printing_hour = printing_hour; }
void Daily::setPublishmentArea(string publishment_area) { this->publishment_area = publishment_area; }

void Daily::putDetails(ofstream& OutputFile) {
    Magazine::putDetails(OutputFile);
    OutputFile << this->printing_hour << endl;
    OutputFile << this->publishment_area << endl;
}

void Daily::printDetails() {
    Magazine::printDetails();
    cout << "DAILY: " << endl;
    cout << "\tPrinting hours: " << this->printing_hour << endl;
    cout << "\tPublishment area: " << this->publishment_area << endl;
}

void Daily::update() {
    Magazine::update();
    cout << "\t\tDAILY" << endl;
    Updater::updateStr("Printing hour", this->printing_hour);
    Updater::updateStr("Publishment area", this->publishment_area);

}

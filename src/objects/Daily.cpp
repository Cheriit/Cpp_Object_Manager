//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Daily.h"

Daily::Daily(): Magazine() {}
Daily::Daily(ifstream& InputFile): Magazine(InputFile) {}

string Daily::getPrintingHour() { return this->printing_hour; }
string Daily::getPublishmentArea() { return this->publishment_area; }

void Daily::setPrintingHour(const string&) { this->printing_hour = printing_hour; }
void Daily::setPublishmentArea(string publishment_area) { this->publishment_area = publishment_area; }

void Daily::putDetails(ofstream& OutputFile) {
    OutputFile << "DAILY" << endl;
    OutputFile << this->printing_hour << endl;
    OutputFile << this->publishment_area << endl;
    Magazine::putDetails(OutputFile);
}

void Daily::printDetails() {
    cout << "DAILY: " << endl;
    cout << "\tPrinting hours: " << this->printing_hour << endl;
    cout << "\tPublishment area: " << this->publishment_area << endl;
    Magazine::printDetails();
}

void Daily::update() {
    Magazine::update();
}
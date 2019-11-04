//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Publisher.h"

Publisher::Publisher() {}
Publisher::Publisher(ifstream &) {}

int Publisher::getFoundingYear() { return this->founding_year; }
string Publisher::getPublisherName() { return this->publisher_name; }
string Publisher::getOriginCountry() { return this->origin_country; }
string Publisher::getCEO() { return this->CEO; }

void Publisher::setFoundingYear(int founding_year) { this->founding_year = founding_year; }
void Publisher::setPublisherName(string publisher_name) { this->publisher_name = publisher_name; }
void Publisher::setOriginCountry(string origin_country) { this->origin_country = origin_country; }
void Publisher::setCEO(string CEO) { this->CEO = CEO; }

void Publisher::putDetails(ofstream& OutputFile) {
    OutputFile << "PUBLISHER" << endl;
    OutputFile << this->founding_year << endl;
    OutputFile << this->origin_country << endl;
    OutputFile << this->CEO << endl;
    OutputFile << this->publisher_name << endl;
}

void Publisher::printDetails() {
    cout << "PUBLISHER: " << endl;
    cout << "\tPublisher's name: " << this->publisher_name << endl;
    cout << "\tFounding year: " << this->founding_year << endl;
    cout << "\tOrigin country: " << this->origin_country << endl;
    cout << "\tCompany's CEO: " << this->CEO << endl;
}

void Publisher::update() {}


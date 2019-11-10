//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Publisher.h"
#include "../../helpers/Reader.h"
#include "../../helpers/Updater.h"

Publisher::Publisher() {
    cout << "\t\tPUBLISHER" << endl;
    Reader::readString("Publisher's name", this->publisher_name);
    Reader::readString("Origin country", this->origin_country);
    Reader::readString("CEO", this->CEO);
    Reader::readNum<int>("Founding year", this->founding_year);
}
Publisher::Publisher(ifstream & InputFile) {
    getline(InputFile, this->publisher_name);
    getline(InputFile, this->origin_country);
    this->founding_year = Reader::readNum(InputFile);
    getline(InputFile, this->CEO);

}

int Publisher::getFoundingYear() { return this->founding_year; }
string Publisher::getPublisherName() { return this->publisher_name; }
string Publisher::getOriginCountry() { return this->origin_country; }
string Publisher::getCEO() { return this->CEO; }

void Publisher::setFoundingYear(int founding_year) { this->founding_year = founding_year; }
void Publisher::setPublisherName(string publisher_name) { this->publisher_name = publisher_name; }
void Publisher::setOriginCountry(string origin_country) { this->origin_country = origin_country; }
void Publisher::setCEO(string CEO) { this->CEO = CEO; }

void Publisher::putDetails(ofstream& OutputFile) {
    OutputFile << this->publisher_name << endl;
    OutputFile << this->origin_country << endl;
    OutputFile << this->founding_year << endl;
    OutputFile << this->CEO << endl;
}

void Publisher::printDetails() {

    cout << "PUBLISHER: " << endl;
    cout << "\tPublisher's name: " << this->publisher_name << endl;
    cout << "\tFounding year: " << this->founding_year << endl;
    cout << "\tOrigin country: " << this->origin_country << endl;
    cout << "\tCompany's CEO: " << this->CEO << endl;
}

void Publisher::update() {
    cout << "\t\tPUBLISHER" << endl;
    Updater::updateStr("Publisher's name", this->publisher_name);
    Updater::updateStr("Origin country", this->origin_country);
    Updater::updateStr("CEO", this->CEO);
    Updater::updateNum<int>("Founding year", this->founding_year);
}


//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Magazine.h"
#include "../../helpers/Reader.h"
#include "../../helpers/Updater.h"

Magazine::Magazine(): Publisher() {
    cout << "\t\tMAGAZINE" << endl;
    Reader::readString("Title", this->title);
    Reader::readString("Magazine number", this->magazine_number);
    Reader::readString("Topic", this->topic);
    Reader::readNum<int>("Pages", this->pages);
    Reader::readNum<float>("Price", this->price);
    Reader::readNum<int>("Circulation", this->circulation);
}
Magazine::Magazine(ifstream& InputFile): Publisher(InputFile) {
    getline(InputFile, this->topic);
    this->pages = Reader::readNum(InputFile);
    this->price = Reader::readNum(InputFile);
    this->circulation = Reader::readNum(InputFile);
    getline(InputFile, this->magazine_number);
    getline(InputFile, this->title);
}

string Magazine::getTopic() { return this->topic; }
int Magazine::getPages() { return this->pages; }
float Magazine::getPrice() { return this->price; }
int Magazine::getCirculation() { return this->circulation; }
string Magazine::getMagazineNumber(){ return this->magazine_number; }
string Magazine::getTitle() { return this->title; }

void Magazine::setTopic(string topic) { this->topic = topic; }
void Magazine::setPages(int pages) { this->pages = pages; }
void Magazine::setPrice(float price) { this->price = price; }
void Magazine::setCirculation(int circulation) { this->circulation = circulation; }
void Magazine::setMagazineNumber(string magazine_number) { this->magazine_number = magazine_number; }
void Magazine::setTitle(string title) { this->title = title; }

void Magazine::putDetails(ofstream& OutputFile) {
    Publisher::putDetails(OutputFile);
    OutputFile << this->topic << endl;
    OutputFile << this->pages << endl;
    OutputFile << this->price << endl;
    OutputFile << this->circulation << endl;
    OutputFile << this->magazine_number << endl;
    OutputFile << this->title << endl;
}

void Magazine::printDetails() {
    Publisher::printDetails();
    cout << "MAGAZINE: " << endl;
    cout << "\tTitle: " << this->title << endl;
    cout << "\tNumber: " << this->magazine_number << endl;
    cout << "\tTopic: " << this->topic << endl;
    cout << "\tPages: " << this->pages << endl;
    cout << "\tPrice: " << this->price << endl;
    cout << "\tCirculation: " << this->circulation << endl;
}

void Magazine::update() {
    Publisher::update();
    Updater::updateStr("Title", this->title);
    Updater::updateStr("Magazine number", this->magazine_number);
    Updater::updateStr("Topic", this->topic);
    Updater::updateNum<int>("Pages", this->pages);
    Updater::updateNum<float>("Price", this->price);
    Updater::updateNum<int>("Circulation", this->circulation);
}


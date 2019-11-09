//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Magazine.h"

Magazine::Magazine(): Publisher() {
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string tmp;

    cout << "\t\tMAGAZINE" << endl;
    cout << "Title:" << endl;
    getline(cin, this->title);
    cout << "Magazine number:" << endl;
    getline(cin, this->magazine_number);
    cout << "Topic:" << endl;
    getline(cin, this->topic);
    cout << "Pages:" << endl;
    cin >> this->pages;
    cout << "Price:" << endl;
    cin >> this->price;
    cout << "Circulation:" << endl;
    cin >> this->circulation;
}
Magazine::Magazine(ifstream& InputFile): Publisher(InputFile) {
    getline(InputFile, this->topic);
    this->pages = Object_interface::readNum(InputFile);
    this->price = Object_interface::readNum(InputFile);
    this->circulation = Object_interface::readNum(InputFile);
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
void Magazine::setCirculation(float circulation) { this->circulation = circulation; }
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
    Object_interface::updateStr("Title", this->title);
    Object_interface::updateStr("Magazine number", this->magazine_number);
    Object_interface::updateStr("Topic", this->topic);
    Object_interface::updateNum<int>("Pages", this->pages);
    Object_interface::updateNum<float>("Price", this->price);
    Object_interface::updateNum<int>("Circulation", this->circulation);

}
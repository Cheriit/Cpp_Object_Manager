//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Magazine.h"

Magazine::Magazine(): Publisher() {}
Magazine::Magazine(ifstream& InputFile): Publisher(InputFile) {}

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
    OutputFile << "MAGAZINE" << endl;
    OutputFile << this->topic << endl;
    OutputFile << this->pages << endl;
    OutputFile << this->price << endl;
    OutputFile << this->circulation << endl;
    OutputFile << this->magazine_number << endl;
    OutputFile << this->title << endl;
    Publisher::putDetails(OutputFile);
}

void Magazine::printDetails() {
    cout << "MAGAZINE: " << endl;
    cout << "\tTitle: " << this->title << endl;
    cout << "\tNumber: " << this->magazine_number << endl;
    cout << "\tTopic: " << this->topic << endl;
    cout << "\tPages: " << this->pages << endl;
    cout << "\tPrice: " << this->price << endl;
    cout << "\tCirculation: " << this->circulation << endl;
    Publisher::printDetails();
}

void Magazine::update() {
    Publisher::update();
}
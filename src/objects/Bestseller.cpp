//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Bestseller.h"


Bestseller::Bestseller(): Book() {
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string tmp;
    cout << "\t\tBESTSELLER" << endl;

    cout << "Bestselling from:" << endl;
    getline(cin, this->bestselling_from);

    cout << "Bestselling to:" << endl;
    getline(cin, this->bestselling_to);

    cout << "Bestselling where:" << endl;
    getline(cin, this->bestselling_where);

    cout << "Score:" << endl;
    cin >> this->score;

    cout << "Sold copies:" << endl;
    cin >> this->sold_copies;
}
Bestseller::Bestseller(ifstream& InputFile): Book(InputFile) {
    this->score = Object_interface::readNum(InputFile);
    getline(InputFile, this->bestselling_from);
    getline(InputFile, this->bestselling_to);
    getline(InputFile, this->bestselling_where);
    this->sold_copies = Object_interface::readNum(InputFile);
}

float Bestseller::getScore() { return this->score; }
string Bestseller::getBestsellingPeriod() { return this->bestselling_from + "-" + this->bestselling_to; }
string Bestseller::getBestsellingWhere() { return this->bestselling_where; }
int Bestseller::getSoldCopies() { return this->sold_copies; }

void Bestseller::setScore(float score) { this->score = score; }
void Bestseller::setBestsellingPeriod(string from, string to) {
    this -> bestselling_from = from;
    this->bestselling_to = to;
}
void Bestseller::setBestsellingWhere(string where) { this->bestselling_where = where; }
void Bestseller::setSoldCopies(int sold_copies) { this->sold_copies = sold_copies; }

void Bestseller::putDetails(ofstream& OutputFile){
    Book::putDetails(OutputFile);
    OutputFile << this->score << endl;
    OutputFile << this->bestselling_from << endl;
    OutputFile << this->bestselling_to << endl;
    OutputFile << this->bestselling_where << endl;
    OutputFile << this->sold_copies << endl;
}
void Bestseller::printDetails() {
    Book::printDetails();
    cout << this->name << endl;
    cout << "BESTSELLER: " << endl;
    cout << "\tScore: " << this->score << endl;
    cout << "\tBestselling period: " << this->bestselling_from << " - " << this->bestselling_to << endl;
    cout << "\tBestselling at: " << this->bestselling_where << endl;
    cout << "\tSold copies: " << this->sold_copies << endl;
}

void Bestseller::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" by " << this->author << " published by " << this->publisher_name << endl;
    cout << "\t sold in " << this->sold_copies << " copies." << endl;
}

std::ostream& operator<<(std::ostream& output, const Bestseller& bestseller) {
    output << bestseller.name;
    return  output;
}
void Bestseller::update() {
    Book::update();
    cout << "\t\tBESTSELLER" << endl;
    Object_interface::updateNum<float>("Score", this->score);
    Object_interface::updateStr("Bestselling from", this->bestselling_from);
    Object_interface::updateStr("Bestselling to", this->bestselling_to);
    Object_interface::updateStr("Bestselling where", this->bestselling_where);
    Object_interface::updateNum<int>("Sold copies", this->sold_copies);
}

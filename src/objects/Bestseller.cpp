//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Bestseller.h"
#include "../../helpers/Reader.h"
#include "../../helpers/Updater.h"


Bestseller::Bestseller(): Book() {
    cout << "\t\tBESTSELLER" << endl;

    Reader::readString("Bestselling from", this->bestselling_from);
    Reader::readString("Bestselling to", this->bestselling_to);
    Reader::readString("Bestselling where", this->bestselling_where);
    Reader::readNum<float>("Score", this->score);
    Reader::readNum<int>("Sold copies", this->sold_copies);
}
Bestseller::Bestseller(ifstream& InputFile): Book(InputFile) {
    this->score = Reader::readNum(InputFile);
    getline(InputFile, this->bestselling_from);
    getline(InputFile, this->bestselling_to);
    getline(InputFile, this->bestselling_where);
    this->sold_copies = Reader::readNum(InputFile);
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

void Bestseller::update() {
    Book::update();
    cout << "\t\tBESTSELLER" << endl;
    Updater::updateNum<float>("Score", this->score);
    Updater::updateStr("Bestselling from", this->bestselling_from);
    Updater::updateStr("Bestselling to", this->bestselling_to);
    Updater::updateStr("Bestselling where", this->bestselling_where);
    Updater::updateNum<int>("Sold copies", this->sold_copies);
}

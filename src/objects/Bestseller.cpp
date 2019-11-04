//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Bestseller.h"

Bestseller::Bestseller(): Book() {}
Bestseller::Bestseller(ifstream& InputFile): Book(InputFile) {}

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
    OutputFile << "BESTSELLER" << endl;
    OutputFile << this->name << endl;
    OutputFile << this->score << endl;
    OutputFile << this->bestselling_from << endl;
    OutputFile << this->bestselling_to << endl;
    OutputFile << this->bestselling_where << endl;
    OutputFile << this->sold_copies << endl;
    Book::putDetails(OutputFile);
}
void Bestseller::printDetails() {
    cout << this->name << endl;
    cout << "BESTSELLER: " << endl;
    cout << "\tScore: " << this->score << endl;
    cout << "\tBestselling period: " << this->bestselling_from << "+" << this->bestselling_to << endl;
    cout << "\tBestselling at: " << this->bestselling_where << endl;
    cout << "\tSold copies: " << this->sold_copies << endl;
    Book::printDetails();
}

void Bestseller::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" by " << this->author << " published by " << this->publisher_name << endl;
    cout << "\t sold in " << this->sold_copies << " copies." << endl;
}

std::ostream& Bestseller::operator<<(std::ostream& output, const Bestseller& bestseller) {
    output << this->getName() << endl;
    output << "\t\"" << this->getTitle() <<"\" by " << this->getAuthor() << " published by " << this->getPublisherName() << endl;
    output << "\t sold in " << this->getSoldCopies() << " copies." << endl;
    return  output;
}
void Bestseller::update() {
    Book::update();
}

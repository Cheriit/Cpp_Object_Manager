//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Book.h"

Book::Book(): Publisher() {}
Book::Book(ifstream& InputFile): Publisher(InputFile) {}

string Book::getISBN() { return this->isbn; }
string Book::getPublishingDate() { return this->publishing_date; }
int Book::getPages(){ return this->pages; }
string Book::getFormat(){ return this->format; }
string Book::getGenre(){ return this->genre; }
CoverType Book::getCover(){ return this->cover; }
float Book::getPrice(){ return this->price; }
string Book::getTitle(){ return this->title; }
string Book::getAuthor(){ return this->author; }

void Book::setISBN(string isbn){ this->isbn = isbn; }
void Book::setPublishingDate(string publishing_date){ this->publishing_date = publishing_date; }
void Book::setPages(int pages){ this->pages = pages; }
void Book::setFormat(string format){ this->format = format; }
void Book::setGenre(string genre){ this->genre = genre; }
void Book::setCover(CoverType cover){ this->cover = cover; }
void Book::setPrice(float price){ this->price = price; }
void Book::setTitle(string title) { this->title = title;}
void Book::setAuthor(string author){ this->author = author; }

void Book::putDetails(ofstream& OutputFile) {
    OutputFile << "BOOK" << endl;
    OutputFile << this->isbn << endl;
    OutputFile << this->publishing_date << endl;
    OutputFile << this->pages << endl;
    OutputFile << this->format << endl;
    OutputFile << this->genre << endl;
    OutputFile << this->cover << endl;
    OutputFile << this->price << endl;
    OutputFile << this->title << endl;
    OutputFile << this->author << endl;
    Publisher::putDetails(OutputFile);
}

void Book::printDetails() {
    cout << "BOOK: " << endl;
    cout << "\tTitle: " << this->title << endl;
    cout << "\tAuthor: " << this->author << endl;
    cout << "\tPublishing date: " << this->publishing_date << endl;
    cout << "\tISBN: " << this->isbn << endl;
    cout << "\tPages: " << this->pages << endl;
    cout << "\tFormat: " << this->format << endl;
    cout << "\tGenre: " << this->genre << endl;
    cout << "\tCover: " << this->cover << endl;
    cout << "\tPrice: " << this->price << endl;
    Publisher::printDetails();
}

void Book::update() {
    Publisher::update();
}
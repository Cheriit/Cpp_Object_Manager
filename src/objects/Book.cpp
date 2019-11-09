//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Book.h"

Book::Book(): Publisher() {
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string tmp;
    cout << "\t\tBOOK" << endl;

    cout << "Title:" << endl;
    getline(cin, this->title);

    cout << "Author:" << endl;
    getline(cin, this->author);

    cout << "Publishing date:" << endl;
    getline(cin, this->publishing_date);

    cout << "ISBN:" << endl;
    getline(cin, this->isbn);

    cout << "Format:" << endl;
    getline(cin, this->format);

    cout << "Genre:" << endl;
    getline(cin, this->genre);

    cout << "Pages:" << endl;
    cin >> this->pages;

    cout << "Price:" << endl;
    cin >> this->price;
}
Book::Book(ifstream& InputFile): Publisher(InputFile) {
    getline(InputFile, this->isbn);
    getline(InputFile, this->publishing_date);
    this->pages = Object_interface::readNum(InputFile);
    getline(InputFile, this->format);
    getline(InputFile, this->genre);
    this->price = Object_interface::readNum(InputFile);
    getline(InputFile, this->title);
    getline(InputFile, this->author);

}

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
    Publisher::putDetails(OutputFile);
    OutputFile << this->isbn << endl;
    OutputFile << this->publishing_date << endl;
    OutputFile << this->pages << endl;
    OutputFile << this->format << endl;
    OutputFile << this->genre << endl;
//    OutputFile << this->cover << endl;
    OutputFile << this->price << endl;
    OutputFile << this->title << endl;
    OutputFile << this->author << endl;
}

void Book::printDetails() {
    Publisher::printDetails();
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
}

void Book::update() {
    Publisher::update();
    cout << "\t\tBOOK" << endl;
    Object_interface::updateStr("Title", this->title);
    Object_interface::updateStr("Author", this->author);
    Object_interface::updateStr("Publishing date", this->publishing_date);
    Object_interface::updateStr("ISBN", this->isbn);
    Object_interface::updateStr("Format", this->format);
    Object_interface::updateStr("Genre", this->genre);
    Object_interface::updateNum<int>("Pages", this->pages);
    Object_interface::updateNum<float>("Pages", this->price);
}
//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Book.h"
#include "../../helpers/Reader.h"
#include "../../helpers/Updater.h"

Book::Book(): Publisher() {
    cout << "\t\tBOOK" << endl;
    Reader::readString("Title", this->title);
    Reader::readString("Author", this->author);
    Reader::readString("Publishing date", this->publishing_date);
    Reader::readString("ISBN", this->isbn);
    Reader::readString("Format", this->format);
    Reader::readString("Genre", this->genre);
    Reader::readNum<int>("Pages", this->pages);
    Reader::readNum<float>("Price", this->price);
    int tmp;
    Reader::readNum("Cover type (1- Paperback, 2- hardback casewrap, 3- Hardback Dust Jacket)", tmp);
    this->setCover(tmp);
}
Book::Book(ifstream& InputFile): Publisher(InputFile) {
    getline(InputFile, this->isbn);
    getline(InputFile, this->publishing_date);
    this->pages = Reader::readNum(InputFile);
    getline(InputFile, this->format);
    getline(InputFile, this->genre);
    this->setCover(Reader::readNum(InputFile));
    this->price = Reader::readNum(InputFile);
    getline(InputFile, this->title);
    getline(InputFile, this->author);

}

string Book::getISBN() { return this->isbn; }
string Book::getPublishingDate() { return this->publishing_date; }
int Book::getPages(){ return this->pages; }
string Book::getFormat(){ return this->format; }
string Book::getGenre(){ return this->genre; }
string Book::getCover(){
    switch(this->cover)
    {
        case 1:
            return "Paperback";
        case 2:
            return "Hardback Casewrap";
        case 3:
            return "Hardback Dust Jacket";
        default:
            return "Unspecified";
    }
}
float Book::getPrice(){ return this->price; }
string Book::getTitle(){ return this->title; }
string Book::getAuthor(){ return this->author; }

void Book::setISBN(string isbn){ this->isbn = isbn; }
void Book::setPublishingDate(string publishing_date){ this->publishing_date = publishing_date; }
void Book::setPages(int pages){ this->pages = pages; }
void Book::setFormat(string format){ this->format = format; }
void Book::setGenre(string genre){ this->genre = genre; }
void Book::setCover(int cover){
    if(cover>3)
        this->cover = static_cast<CoverType>(0);
    else
        this->cover = static_cast<CoverType>(cover);
}
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
    OutputFile << this->cover << endl;
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
    cout << "\tCover: " << this->getCover() << endl;
    cout << "\tPrice: " << this->price << endl;
}

void Book::update() {
    Publisher::update();
    cout << "\t\tBOOK" << endl;
    Updater::updateStr("Title", this->title);
    Updater::updateStr("Author", this->author);
    Updater::updateStr("Publishing date", this->publishing_date);
    Updater::updateStr("ISBN", this->isbn);
    Updater::updateStr("Format", this->format);
    Updater::updateStr("Genre", this->genre);
    int tmp = this->cover;
    Updater::updateNum("Cover type: 1- Paperback, 2- hardback casewrap, 3- Hardback Dust Jacket", tmp);
    this->setCover(tmp);
    Updater::updateNum<int>("Pages", this->pages);
    Updater::updateNum<float>("Pages", this->price);
}
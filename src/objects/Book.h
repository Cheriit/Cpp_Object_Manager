//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_BOOK_H
#define PROJECT01_BOOK_H

#include <ostream>
#include "Publisher.h"
#include "../../helpers/CoverType.h"
using namespace std;

class Book: public Publisher {
private:
    string isbn;
    string publishing_date;
    int pages;
    string format;
    string genre;
    CoverType cover;
    float price;
protected:
    string title;
    string author;
public:
    Book();
    Book(ifstream&);
    string getTitle();
    string getISBN();
    string getAuthor();
    string getPublishingDate();
    int getPages();
    string getFormat();
    string getGenre();
    CoverType getCover();
    float getPrice();
    void putDetails(ofstream&);
    void printDetails();
    void setTitle(string);
    void setISBN(string);
    void setAuthor(string);
    void setPublishingDate(string);
    void setPages(int);
    void setFormat(string);
    void setGenre(string);
    void setCover(CoverType);
    void setPrice(float);
    void update();
};


#endif //PROJECT01_BOOK_H

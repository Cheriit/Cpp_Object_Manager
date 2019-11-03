//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_BOOK_H
#define PROJECT01_BOOK_H

#include "Publisher.h"
#include "../../helpers/CoverType.h"
using namespace std;

class Book: public Publisher {
private:
    string isbn[13];
    string publishing_date[10];
    int pages;
    string format(9);
    string genre();
    CoverType cover;
    float price();
protected:
    string title;
    string author;
public:
    string getTitle();
    string getISBN();
    string getAuthor();
    string getPublishingDate();
    int getPages();
    string getFormat();
    string getGenre();
    CoverType getCover();
    float getPrice();
    string getDetails();
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

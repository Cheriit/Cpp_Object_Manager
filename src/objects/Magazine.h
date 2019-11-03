//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MAGAZINE_H
#define PROJECT01_MAGAZINE_H


#include "Book.h"

class Magazine: public Book{
private:
    string topic;
    int pages;
    float price;
    int circulation;
protected:
    string magazine_number;
    string title;
public:
    string getManagzineNumber();
    string getTopic();
    int getPages();
    string getTitle();
    float getPtice();
    string getCirculation();
    string getDetails();
    void printDetails();
    void setMagazineNumber(string);
    void setTopic(string);
    void setPages(int);
    void setTitle(string);
    void setPrice(float);
    void setCirculation(float);
    void update();
};


#endif //PROJECT01_MAGAZINE_H

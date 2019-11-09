//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MAGAZINE_H
#define PROJECT01_MAGAZINE_H


#include "Book.h"

class Magazine: public Publisher{
private:
    string topic;
    int pages;
    float price;
    int circulation;
protected:
    string magazine_number;
    string title;
public:
    Magazine();
    explicit Magazine(ifstream&);
    string getMagazineNumber();
    string getTopic();
    int getPages();
    string getTitle();
    float getPrice();
    int getCirculation();
    void putDetails(ofstream&) override;
    void printDetails() override;
    void setMagazineNumber(string);
    void setTopic(string);
    void setPages(int);
    void setTitle(string);
    void setPrice(float);
    void setCirculation(float);
    void update() override;
};


#endif //PROJECT01_MAGAZINE_H

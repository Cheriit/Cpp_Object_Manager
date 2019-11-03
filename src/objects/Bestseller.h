//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_BESTSELLER_H
#define PROJECT01_BESTSELLER_H


#include "Book.h"

class Bestseller: public Book {
private:
    float score;
    string bestselling_from;
    string bestselling_to;
    string bestselling_where;
protected:
    int sold_copies;
public:
    int getSoldCopies();
    float getScore();
    string getBestsellingPeriod();
    string getBestsellingWhere();
    string getDetails();
    void printDetails();
    void printShortDescription();
    void setSoldCopies(int);
    void setScore(float);
    void setBestsellingPeriod(string, string);
    void setBestsellingWhere(string);
    void update();
    friend std::ostream& operator<<(std::ostream& output, const Bestseller& bestseller);
};


#endif //PROJECT01_BESTSELLER_H

//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_POPULARSCIENCE_H
#define PROJECT01_POPULARSCIENCE_H


#include <vector>
#include "Book.h"

class PopularScience: public Book {
private:
    vector<string> sources;
protected:
    string field_of_study;
public:
    string getFieldOfStudy();
    vector<string> getSources();
    void putDetails(ofstream&);
    void printDetails();
    void printShortDescription();
    void printSources();
    void setFieldOfStudy(string);
    void setSources(vector<string>);
    void addSource(string);
    void update();
    friend std::ostream& operator<<(std::ostream& output, const PopularScience& popularScience);
};


#endif //PROJECT01_POPULARSCIENCE_H

//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_PUBLISHER_H
#define PROJECT01_PUBLISHER_H

#include <string>
#include "Object_interface.h"

using namespace std;
class Publisher: public Object_interface {
private:
    int founding_year;
    string origin_country;
    string CEO;
protected:
    string publisher_name;
public:
    Publisher();
    explicit Publisher(ifstream &);
    int getFoundingYear();
    string getPublisherName();
    string getOriginCountry();
    string getCEO();
    void putDetails(ofstream&) override;
    void printDetails() override;
    void setFoundingYear(int);
    void setPublisherName(string);
    void setOriginCountry(string);
    void setCEO(string);
    void update() override;
};


#endif //PROJECT01_PUBLISHER_H

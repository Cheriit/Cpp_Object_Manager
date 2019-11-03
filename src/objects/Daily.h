//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_DAILY_H
#define PROJECT01_DAILY_H


#include "Magazine.h"

class Daily: virtual public Magazine{
private:
    string printing_hour;
protected:
    string publishment_area;
public:
    string getPrintingHour();
    string getPublishmentArea();
    string getDetails();
    void printDetails();
    void setPringingHour(string);
    void setPublishmentArea(string);
    void update();
};


#endif //PROJECT01_DAILY_H

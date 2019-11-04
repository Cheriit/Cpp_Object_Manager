//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MAGAZINETYPE_H
#define PROJECT01_MAGAZINETYPE_H


#include "Magazine.h"

template <class T> class MagazineType: virtual public Magazine {
private:
    string bar_code;
protected:
    T publish_day;
public:
    T getPublishDay();
    string getBarCode();
    void putDetails(ofstream&);
    void printDetails();
    void setPublishDay(T);
    void setBarCode(string);
    void update();
};


#endif //PROJECT01_MAGAZINETYPE_H

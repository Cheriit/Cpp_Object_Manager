//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MAGAZINETYPE_H
#define PROJECT01_MAGAZINETYPE_H


#include "Magazine.h"

template <class T>
        class MagazineType: virtual public Magazine {
private:
    string bar_code;
protected:
    T publish_day;
public:
    MagazineType<T>();
    explicit MagazineType<T>(ifstream&);
    T getPublishDay();
    string getBarCode();
    void setPublishDay(T);
    void setBarCode(string);
};

template <class T>
MagazineType<T>::MagazineType() {}
template <class T>
MagazineType<T>::MagazineType(ifstream&) {}

template <class T>
T MagazineType<T>::getPublishDay() { return this->publish_day; }
template <class T>
string MagazineType<T>::getBarCode() { return  this->bar_code; }
template <class T>
void MagazineType<T>::setPublishDay(T day) { this->day = day; }
template <class T>
void MagazineType<T>::setBarCode(string bar_code) { this->bar_code = bar_code; }


#endif //PROJECT01_MAGAZINETYPE_H

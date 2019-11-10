//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MAGAZINETYPE_H
#define PROJECT01_MAGAZINETYPE_H


#include "Magazine.h"
/**
 *  Magazine's type class
 *  Inherits virtually from Magazine
 */
template <class T>
        class MagazineType: virtual public Magazine {
private:
    string bar_code;
protected:
    T publish_day;
public:
    /**
     * Creates new instance of magazine type interacting with an user
     */
    MagazineType<T>();
    /**
     * Creates new instance of magazine type based on file's content
     * @param ifstream& file stream
     */
    explicit MagazineType<T>(ifstream&);
    /**
     * Get publish day
     * @return T
     */
    T getPublishDay();
    /**
     * Get bar code
     * @return string
     */
    string getBarCode();
    /**
     * Set magazine type publish day
     * @param T Publish day
     */
    void setPublishDay(T);
    /**
     * Set magazine type bar code
     * @param string bar code
     */
    void setBarCode(string);
};

template <class T>
MagazineType<T>::MagazineType() {}
template <class T>
MagazineType<T>::MagazineType(ifstream& InputFile) {}

template <class T>
T MagazineType<T>::getPublishDay() { return this->publish_day; }
template <class T>
string MagazineType<T>::getBarCode() { return  this->bar_code; }
template <class T>
void MagazineType<T>::setPublishDay(T day) { this->publish_day = day; }
template <class T>
void MagazineType<T>::setBarCode(string bar_code) { this->bar_code = bar_code; }


#endif //PROJECT01_MAGAZINETYPE_H

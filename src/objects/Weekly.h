//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_WEEKLY_H
#define PROJECT01_WEEKLY_H


#include "../../helpers/WeekDay.h"
#include "MagazineType.h"
class Weekly: public MagazineType<WeekDay> {
public:
    Weekly();
    Weekly(ifstream&);
};


#endif //PROJECT01_WEEKLY_H

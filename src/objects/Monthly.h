//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MONTHLY_H
#define PROJECT01_MONTHLY_H

#include "MagazineType.h"

class Monthly: public MagazineType<int> {
public:
    Monthly();
    explicit Monthly(ifstream&);
    void printShortDescription();
    void putDetails(ofstream&) override;
    void printDetails() override;
    void update() override;
    friend std::ostream& operator<<(std::ostream& output, const Monthly& monthly);

};


#endif //PROJECT01_MONTHLY_H

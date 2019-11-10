//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MONTHLY_H
#define PROJECT01_MONTHLY_H

#include "MagazineType.h"
/**
 * Monthly magazine class
 */
class Monthly: public MagazineType<int> {
public:
    /**
     * Creates new instance of monthly magazine interacting with an user
     */
    Monthly();
    /**
     * Creates new instance of monthly magazine based on file's content
     * @param ifstream& file stream
     */
    explicit Monthly(ifstream&);
    /**
     * Prints object's short version of data
     */
    void printShortDescription();
    /**
    * Save object data into a file
    * @param ofstream& files stream
    */
    void putDetails(ofstream&) override;
    /**
     * Prints object's data
     */
    void printDetails() override;
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
};


#endif //PROJECT01_MONTHLY_H

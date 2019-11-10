//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_WEEKLY_H
#define PROJECT01_WEEKLY_H


#include "../../helpers/WeekDay.h"
#include "MagazineType.h"
class Weekly: public MagazineType<WeekDay> {
public:
    /**
     * Creates new instance of weekly magazine interacting with an user
     */
    Weekly();
    /**
     * Creates new instance of weekly magazine based on file's content
     * @param ifstream& file stream
     */
    explicit Weekly(ifstream&);
    /**
     * Set magazine's publish day, convert int to WeekDay
     * @param int publish day
     */
    void setPublishDay(int);
    /**
     * Get magazine's publish day, convert WeekDay to string
     * @return string
     */
    string getPublishDay();
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


#endif //PROJECT01_WEEKLY_H

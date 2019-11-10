//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_DAILY_H
#define PROJECT01_DAILY_H


#include "Magazine.h"
/**
 * Daily magazine class
 */
class Daily: virtual public Magazine{
private:
    string printing_hour;
protected:
    string publishment_area;
public:
    /**
     * Creates new instance of daily magazine, interacting with an user
     */
    Daily();
    /**
     * Creates new instance of daily magazine based on file's content
     * @param ifstream& file stream
     */
    explicit Daily(ifstream&);
    /**
     * Get printing hours
     * @return string printing_hours
     */
    string getPrintingHour();
    /**
     * Get publishment area
     * @return string publishment area
     */
    string getPublishmentArea();
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
     * Set daily magazine's printing hours
     * @param string printing hours
     */
    void setPrintingHour(const string&);
    /**
     * Set daily magazine's publishment area
     * @param string publishment area
     */
    void setPublishmentArea(string);
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
};


#endif //PROJECT01_DAILY_H

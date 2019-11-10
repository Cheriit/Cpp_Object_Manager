//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_PUBLISHER_H
#define PROJECT01_PUBLISHER_H

#include <string>
#include "Object_interface.h"

using namespace std;
/**
 * Publisher class
 */
class Publisher: public Object_interface {
private:
    int founding_year{};
    string origin_country;
    string CEO;
protected:
    string publisher_name;
public:
    /**
     * Creates new instance of publisher interacting with an user
     */
    Publisher();
    /**
     * Creates new instance of publisher based on file's content
     * @param ifstream& file stream
     */
    explicit Publisher(ifstream &);
    /**
     * Get publisher's founding year
     * @return int
     */
    int getFoundingYear();
    /**
     * Get publisher's name
     * @return string
     */
    string getPublisherName();
    /**
     * Get publisher's origin country
     * @return string
     */
    string getOriginCountry();
    /**
     * Get publisher's CEO
     * @return string
     */
    string getCEO();
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
     * Set publisher's founding year
     * @param int founding year
     */
    void setFoundingYear(int);
    /**
     * Set publisher's name
     * @param string name
     */
    void setPublisherName(string);
    /**
     * Set publisher's origin country
     * @param string origin country
     */
    void setOriginCountry(string);
    /**
     * Set publisher's ceo
     * @param string ceo
     */
    void setCEO(string);
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
};


#endif //PROJECT01_PUBLISHER_H

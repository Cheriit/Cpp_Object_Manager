//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_POPULARSCIENCE_H
#define PROJECT01_POPULARSCIENCE_H


#include <vector>
#include "Book.h"

/**
 * PopularScience book class
 */
class PopularScience: public Book {
private:
    vector<string> sources;
protected:
    string field_of_study;
public:
    /**
     * Creates new instance of popular science book interacting with an user
     */
    PopularScience();
    /**
    * Creates new instance of popular science book based on file's content
    * @param ifstream& file stream
    */
    explicit PopularScience(ifstream&);
    /**
     * Get field of study
     * @return string
     */
    string getFieldOfStudy();
    /**
     * Get sources
     * @return vector<string>
     */
    vector<string> getSources();
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
     * Prints object's short version of data
     */
    void printShortDescription();
    /**
     * Prints sources in console output
     */
    void printSources();
    /**
     * Set field of study
     * @param string field of study
     */
    void setFieldOfStudy(string);
    /**
     * Set sources to a given vector
     * @param vector<string> sources
     */
    void setSources(vector<string>);
    /**
     * Add source into the vector
     * @param string source
     */
    void addSource(string);
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
    /**
     * Destroys object instance
     */
    ~PopularScience();
};


#endif //PROJECT01_POPULARSCIENCE_H

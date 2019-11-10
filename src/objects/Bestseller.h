//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_BESTSELLER_H
#define PROJECT01_BESTSELLER_H


#include "Book.h"

/**
 * Bestseller class
 */
class Bestseller: public Book {
private:
    float score;
    string bestselling_from;
    string bestselling_to;
    string bestselling_where;
protected:
    int sold_copies;
public:
    /**
     * Creates new instance of bestseller interaction with an user
     */
    Bestseller();
    /**
     * Creates new instance of bestseller based on file's content
     * @param ifstream& file stream
     */
    explicit Bestseller(ifstream&);
    /**
     * Get amount of sold copies
     * @return int
     */
    int getSoldCopies();
    /**
     * Get book's score
     * @return float
     */
    float getScore();
    /**
     * Get bestseller from - to
     * @return string
     */
    string getBestsellingPeriod();
    /**
     * Get bestselling place
     * @return string
     */
    string getBestsellingWhere();
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
     * Set sold copies amount
     * @param int sold_copies
     */
    void setSoldCopies(int);
    /**
     * Set score
     * @param float score
     */
    void setScore(float);
    /**
     * Set bestselling from - to
     * @param string bestselling_from
     * @param string bestselling_to
     */
    void setBestsellingPeriod(string, string);
    /**
     * Set bestselling place
     * @param string place
     */
    void setBestsellingWhere(string);
    /**
    * Updates objects content interacting with the user
    */
    void update() override;
};
#endif //PROJECT01_BESTSELLER_H

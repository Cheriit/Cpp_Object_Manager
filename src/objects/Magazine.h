//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_MAGAZINE_H
#define PROJECT01_MAGAZINE_H


#include "Book.h"

class Magazine: public Publisher{
private:
    string topic;
    int pages;
    float price;
    int circulation;
protected:
    string magazine_number;
    string title;
public:
    /**
     * Creates new instance of magazine interacting with an user
     */
    Magazine();
    /**
     * Creates new instance of magazine based on file's content
     * @param ifstream& file stream
     */
    explicit Magazine(ifstream&);
    /**
     * Get magazine's number
     * @return string
     */
    string getMagazineNumber();
    /**
     * Get magazine's topic
     * @return string
     */
    string getTopic();
    /**
     * Get magazine's pages
     * @return int
     */
    int getPages();
    /**
     * Get magazine's title
     * @return string
     */
    string getTitle();
    /**
     * Get magazine's price
     * @return float
     */
    float getPrice();
    /**
     * Get magazine's circulation
     * @return int
     */
    int getCirculation();
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
     * Set magazine's number
     * @param string number
     */
    void setMagazineNumber(string);
    /**
     * Set magazine's topic
     * @param string topic
     */
    void setTopic(string);
    /**
     * Set magazine's pages amount
     * @param int pages amount
     */
    void setPages(int);
    /**
     * Set magazine's title
     * @param string title
     */
    void setTitle(string);
    /**
     * Set magazine's price
     * @param float price
     */
    void setPrice(float);
    /**
     * Set magazine's circulation
     * @param float circulation
     */
    void setCirculation(int);
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
};


#endif //PROJECT01_MAGAZINE_H

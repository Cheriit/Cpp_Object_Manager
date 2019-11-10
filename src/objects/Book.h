//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_BOOK_H
#define PROJECT01_BOOK_H

#include <ostream>
#include "Publisher.h"
#include "../../helpers/CoverType.h"
using namespace std;

/**
 * Book class
 */
class Book: public Publisher {
private:
    string isbn;
    string publishing_date;
    int pages;
    string format;
    string genre;
    CoverType cover;
    float price;
protected:
    string title;
    string author;
public:
    /**
     * Creates new instance of book interacting with an user
     */
    Book();
    /**
     * Creates new instance of book based on file's content
     * @param ifstream& file stream
     */
    explicit Book(ifstream&);
    /**
     * Return book's title
     * @return string
     */
    string getTitle();
    /**
     * Return book's isbn
     * @return string
     */
    string getISBN();
    /**
     * Return book's author
     * @return string
     */
    string getAuthor();
    /**
     * Return book's publishing date
     * @return string
     */
    string getPublishingDate();
    /**
     * Return book's pages amount
     * @return int
     */
    int getPages();
    /**
     * Return book's format
     * @return string
     */
    string getFormat();
    /**
     * Return book's genre
     * @return string
     */
    string getGenre();
    /**
     * Return book's cover description
     * @return string
     */
    string getCover();
    /**
     * Return book's price
     * @return float
     */
    float getPrice();
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
     * Set book's title
     * @param string title
     */
    void setTitle(string);
    /**
      * Set book's ISBN
      * @param string ISBN
      */
    void setISBN(string);
    /**
      * Set book's author
      * @param string author
      */
    void setAuthor(string);
    /**
      * Set book's publishing date
      * @param string publishing date
      */
    void setPublishingDate(string);
    /**
      * Set book's pages
      * @param int pages
      */
    void setPages(int);
    /**
      * Set book's format
      * @param string format
      */
    void setFormat(string);
    /**
      * Set book's genre
      * @param string genre
      */
    void setGenre(string);
    /**
      * Set book's cover type
      * @param int Cover type code
      */
    void setCover(int);
    /**
      * Set book's price
      * @param float price
      */
    void setPrice(float);
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
};


#endif //PROJECT01_BOOK_H

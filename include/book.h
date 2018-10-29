/************************************************************************
* FILENAME:      book.h
*
* DESCRIPTION/PURPOSE: Header file for book inventory class
*
* AUTHOR:    20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 8/22/2018
* SUBMISSION DATE:
*
* Design: (Explain below algorithm in steps)
* 1) private data members
* 2) public functions to manipulate private members
* 3)
* 4)
* ...
*
* IMPORTANT NOTES:
*
************************************************************************/
#ifndef book_H
#define book_H
#include <string.h>
class book
{
private:
    char *author;
    char *title;
    int price;
    char *publisher;
    int stock;
public:
    book();
    ~book();
    void add_data(char *author,char *title,int price,char *publisher,int stock);
    char* get_name();
    char* get_title();
    int get_price();
    int get_stock();
    void show_data();
};

#endif /* book_H */


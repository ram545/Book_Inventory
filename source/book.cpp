/**********************************************************************
* FILENAME:        book.cpp
*
* DESCRIPTION/PURPOSE: implements methods for book inventory class
*
* AUTHOR:    20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 8/22/2018
* SUBMISSION DATE:
*
**********************************************************************/

#include <iostream>
#include "../include/book.h"
using namespace std;

book::book(){
    int len = 0;
    this -> author = new char[len+1];
    this -> title = new char[len+1];
    this -> price = 0;
    this -> publisher = new char[len+1];
    this -> stock = 0;
}

void book::add_data(char *author,char *title,int price,char *publisher,int stock){
    int len;
    len = strlen(author);
    this->author = new char[len+1];
    strcpy(this->author,author);
    len = strlen(title);
    this->title = new char[len+1];
    strcpy(this->title,title);
    this -> price = price;
    len = strlen(publisher);
    this->publisher = new char[len+1];
    strcpy(this->publisher,publisher);
    this->stock = stock;
}

book::~book(){
    delete []author;
    delete []title;
    delete []publisher;
    stock = 0;
    price = 0;
}

void book::show_data(){
    cout << "Author Name   " << author << endl;
    cout << "Title of Book " << title << endl;
    cout << "Price         " << price << endl;
    cout << "Publisher     " << publisher << endl;
    cout << "Stock         " << stock << endl;
}

char* book::get_name(){
    return author;
}

char* book::get_title(){
    return title;
}

int book::get_price(){
    return price;
}

int book::get_stock(){
    return stock;
}

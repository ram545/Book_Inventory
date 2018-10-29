/**********************************************************************
* FILENAME:        main.cpp
*
* DESCRIPTION/PURPOSE: To manipulate the book inventory by creating an interactive session.
*
* AUTHOR:    20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 8/22/2018
* SUBMISSION DATE:
*
*
* Design: (Explain below algorithm in steps)
* 1) Check the name and title with the record
* 2) if record is present ask for the number of copies required
* 3) if stock is available print the cost
* 4)
* ...
*
* IMPORTANT NOTES:
*
**********************************************************************/

#include <bits/stdc++.h>
#include "../include/book.h"
using namespace std;
void input(book& rec);
bool comp(char* str1,char* str2);
//maxSize is used to vary the number of records
int maxSize = 5;

int main(int argc, char **argv)
{
    char *author,*title;
    int stock;
    int counter=0;
    char ch;
    bool flag;
    book record[maxSize];
    // To give input through the console use this
    while(counter < maxSize){
        input(record[counter]);
        counter++;
    }
    //for giving non console input
    /*
    record[0].add_data("ayn rand","ayn rand institute",700,"facebook",20);
    record[1].add_data("ernest hemingway","central images",500,"getty images",10);
    record[2].add_data("joan didion","jemal countess",400,"getty images",20);
    record[3].add_data("the red sari","javier moro",900,"penguin",5);
    record[4].add_data("j r r tolkein","the hobbit",1000,"fresh",2);
    */
    do{
        cout << "Welcome to the Inventory" << endl;
        cout << "Enter the author and title of the book you want to search" << endl;
        author = new char[20];
        title = new char[50];
        cin.getline(author,20);
        cin.getline(title,50);
        flag = false;
        for(counter=0;counter<maxSize;counter++){
            if(comp(author,record[counter].get_name()) && comp(title,record[counter].get_title())){
                flag = true;
                break;
            }
        }
        if(flag){
            record[counter].show_data();
            cout << "Enter the number of books required" << endl;
            cin >> stock;
            if(stock <= record[counter].get_stock())
                cout << stock*record[counter].get_price() << endl;
            else
                cout << "Required books not in stock" << endl;
        }
        else{
            cout << "The requested book is not available" << endl;
        }
        cout << "Do you want to search for another book  (Y/N)" << endl;
        cin >> ch;
        delete[] author;
        delete[] title;
    }while(ch == 'Y' || ch == 'y');
}
//used to compare two strings
bool comp(char* str1,char* str2){
    int i,len=strlen(str1);
    if(strlen(str1)!=strlen(str2))
        return 0;
    else{
        for(i=0;i<len;i++){
            if(tolower(str1[i]) == tolower(str2[i]))
                continue;
            else{
                return 0;
            }
        }
    }
    return 1;
}
//used to take input from console and add a new book entry
void input(book& rec)
{
    char* author,*title,*publisher;
    int price,stock;
    cout << "Enter Name of the author" << endl;
    author = new char[20];
    cin.getline(author,20);
    cout << "Enter the Book Title" << endl;
    title = new char[50];
    cin.getline(title,50);
    cout << "Enter the Price of Book" << endl;
    cin >> price;
    cin.ignore(256, '\n');
    cout << "Enter the name of the publisher" << endl;
    publisher = new char[30];
    cin.getline(publisher,50);
    cout << "Enter the available stock" << endl;
    cin >> stock;
    cin.ignore(256, '\n');
    rec.add_data(author,title,price,publisher,stock);
    delete[] author;
    delete[] title;
    delete[] publisher;
}
/***********************************************************************
Test Cases:
Tc01:
 Purpose: to test the functionality
 Preconditions if any: uncomment 37 and 40 and comment 42 to 46
 Inputs:
ayn rand
ayn rand institute
700
facebook
20
ernest hemingway
central images
500
getty images
10
joan didion
jemal countess
400
getty images
20
the red sari
javier moro
900
penguin
5
j r r tolkein
the hobbit
1000
fresh
2
 Expected output:
 Actual output:
 Result: PASS/FAIL


Tc02:
 Purpose: to test the functionality
 Preconditions if any: comment 37 and 40 and uncomment 42 to 46
 Inputs: give names according to the prompts on console
 Expected output:
 Actual output:
 Result: PASS/FAIL
ans so on.

***********************************************************************/

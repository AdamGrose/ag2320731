/* 
 * File:   main.cpp
 * Author: Adam Grose
 * Created on April 21, 2014, 4:00 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Account.h"

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void getId(account&);
void getBal(account&);
void checks(account *);
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Menu for Problems
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1: problem1();break;
            default: def(inN);}
    }while(inN<7);

    return 0;
}

void problem1(){
    account bankRec;
    getId(bankRec);
    getBal(bankRec);
}

void getId(account& bankRec){
    cout<<"Enter your 5 digit bank id number."<<endl;
    do{
       cin>>bankRec.id;
       if(bankRec.id>99999||bankRec.id<10000){
           cout<<"Invalid id. Re-enter."<<endl;
       }
    }while(bankRec.id>99999||bankRec.id<10000);
    cout<<"Your bank id number is "<<bankRec.id<<endl;
    
}

void getBal(account& bankRec){
    cout<<"Enter your beginning balance in whole dollars?"<<endl;
    cout<<"$";
    cin>>bankRec.begBlnc;
    cout<<"your beginning balance was $"<<bankRec.begBlnc<<endl;
}

void Menu(){
    cout<<"Enter 1 for problem 1.\n";
    cout<<"Enter 2 for problem 2.\n";
    cout<<"Enter 3 for problem 3.\n";
    cout<<"Enter 4 for problem 4.\n";
    cout<<"Enter 5 for problem 5.\n";
    cout<<"Enter 6 for problem 6.\n";
    cout<<"Enter 7 to exit.\n";
}

int getN(){
    int getN;
    cin>>getN;
    return getN;
}

void def(int getN){
    cout<<"you typed "<<getN<<" to exit the program.\n";
}



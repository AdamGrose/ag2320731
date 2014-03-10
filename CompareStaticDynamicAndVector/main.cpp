/* 
 * File:   main.cpp
 * Author: Adam Grose
 * Created on March 10, 2014, 1:15 PM
 */

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Global Constants

//function prototypes
void filStat(int [],int);//Fill a static array
void prnStat(int [],int,int);//Print a static array
int *fillDyn(int);//Fill a dynamic array
void prntDyn(int [],int,int);//Print a dynamic array
void destroy(int []);
void fillVec(vector<int> &,int);
void prntVec(vector<int> &,int);

//Execution begins here
main(int argc, char** argv) {
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare our static variables
    const int SIZE=100;
    int sArray[SIZE];
    //Fill the static array
        filStat(sArray,SIZE);
        //Print the static array
        prnStat(sArray,SIZE,10);
    //Declare our dynamic array and fill
        int size=SIZE;
        int *dArray=fillDyn(size);
        //Print the dynamic array
        prntDyn(dArray,size,10);
        //Destroy the memory allocated
        destroy(dArray);
    //Declare the Vector
        vector<int> vArray;
        //Fill the Vector
        fillVec(vArray,size);
        //Print the vector
        prntVec(vArray,10);
    //Exit Stage Right
    return 0;
}

void destroy(int a[]){
    delete []a;
    a=0;
}

//Fill a dynamic array i.e. vector
//2 Digit numbers
void fillVec(vector<int> &a,int n){
      for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
    }
}

//Fill a dynamic array
//2 Digit numbers
int *fillDyn(int n){
    //Declare and allocate the dynamic array
    if(n<2)n=2;
    //Allocate memory
    int *a=new int[n];
    //Fill with data
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    //Return and exit with memory allocated array
    return a;
}

//Fill a static array
//2 Digit numbers
void filStat(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void prntVec(vector<int> &a,int perLine){
      cout<<endl;
    cout<<"This is a Vector Array!"<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Print a dynamic array
void prntDyn(int a[],int n,int perLine){
    cout<<endl;
    cout<<"This is a Dynamic Array!"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}


//Print a static array
void prnStat(int a[],int n,int perLine){
    cout<<endl;
    cout<<"This is a Static Array!"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

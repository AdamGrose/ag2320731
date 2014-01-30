/* 
 * File:   main.cpp
 * Author: Adam Grose
 * Created on January 29, 2014, 8:18 PM
 * purpose: Midterm
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int inN;
    //Display Menu
    do{
        Menu();
        inN=getN();
        switch (inN){
            case 1:     problem1();break;
            case 2:     problem2();break;
            case 3:     problem3();break;
            case 4:     problem4();break;
            case 5:     problem5();break;
            case 6:     problem6();break;
            default:    def(inN);}
    }while(inN>=1&&inN<=6);

    return 0;
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
    int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    //Output numbers in increasing order displayed where row=col
    //Declare variables
    int n;//Number of lines to output
    //Input n
    cout<<"Enter the number of lines you want to output.\n";
    cin>>n;
    //output as long as i<=n where i is the counter and output, n is the stop point
    for(int i=1;i<=n;i++){
        //set width so that the col=row.
        cout<<setw(i)<<i<<endl;
    }cout<<endl;
    //Exit Stage Right
}

void problem2(){
    //output a line of '*' for 5 numbers
    //Declare Variables
    const int SIZE=5;
    int n[SIZE],choice,n100,n10,number;
    //Initialize array
    cout<<"Enter 5 whole numbers, each between 3 and 27.\n";
    for(int i=0;i<=4;i++){
        cin>>n[i];
    }
    //calculate amount of tens.
    n10=n[0]/10;
    n[0]-=n10*10;
    //If 2 tens, output 20. If 1 ten, output 10
    switch (n10){
        case 2: cout<<"**********"
                    <<"**********";break;
        case 1: cout<<"**********";break;
   
    }
    //Output any single digits
    switch (n[0]){
        case 9: cout<<"*********";break;
        case 8: cout<<"********";break;
        case 7: cout<<"*******";break;
        case 6: cout<<"******";break;
        case 5: cout<<"*****";break;
        case 4: cout<<"****";break;
        case 3: cout<<"***";break;
        case 2: cout<<"**";break;
        case 1: cout<<"*";break;
        default:;
    }cout<<endl;
    n10=n[1]/10;
    n[1]-=n10*10;
    switch (n10){
        case 2: cout<<"**********"
                    <<"**********";break;
        case 1: cout<<"**********";break;
   
    }
    switch (n[1]){
        case 9: cout<<"*********";break;
        case 8: cout<<"********";break;
        case 7: cout<<"*******";break;
        case 6: cout<<"******";break;
        case 5: cout<<"*****";break;
        case 4: cout<<"****";break;
        case 3: cout<<"***";break;
        case 2: cout<<"**";break;
        case 1: cout<<"*";break;
        default:;
    }cout<<endl;
        n10=n[2]/10;
    n[2]-=n10*10;
    switch (n10){
        case 2: cout<<"**********"
                    <<"**********";break;
        case 1: cout<<"**********";break;
   
    }
    switch (n[2]){
        case 9: cout<<"*********";break;
        case 8: cout<<"********";break;
        case 7: cout<<"*******";break;
        case 6: cout<<"******";break;
        case 5: cout<<"*****";break;
        case 4: cout<<"****";break;
        case 3: cout<<"***";break;
        case 2: cout<<"**";break;
        case 1: cout<<"*";break;
        default:;
    }cout<<endl;
        n10=n[3]/10;
    n[3]-=n10*10;
    switch (n10){
        case 2: cout<<"**********"
                    <<"**********";break;
        case 1: cout<<"**********";break;
   
    }
    switch (n[3]){
        case 9: cout<<"*********";break;
        case 8: cout<<"********";break;
        case 7: cout<<"*******";break;
        case 6: cout<<"******";break;
        case 5: cout<<"*****";break;
        case 4: cout<<"****";break;
        case 3: cout<<"***";break;
        case 2: cout<<"**";break;
        case 1: cout<<"*";break;
        default:;
    }cout<<endl;
        n10=n[4]/10;
    n[4]-=n10*10;
    switch (n10){
        case 2: cout<<"**********"
                    <<"**********";break;
        case 1: cout<<"**********";break;
   
    }
    switch (n[4]){
        case 9: cout<<"*********";break;
        case 8: cout<<"********";break;
        case 7: cout<<"*******";break;
        case 6: cout<<"******";break;
        case 5: cout<<"*****";break;
        case 4: cout<<"****";break;
        case 3: cout<<"***";break;
        case 2: cout<<"**";break;
        case 1: cout<<"*";break;
        default:;
    }cout<<endl<<endl;
    //Exit Stage Right
}

void problem3(){
    unsigned short acntNum,begBal,checks,deposits;
    float endBal;
    //Input data
    cout<<"Enter your 5 digit account number.\n";
    cin>>acntNum;
    cout<<"Enter your account balance at the beginning of the month."<<endl<<"$";
    cin>>begBal;
    cout<<"Enter the total of the checks written in $'s"<<endl<<"$";
    cin>>checks;
    cout<<"Enter the total of of all deposits made to this account this month in $'s"<<endl<<"$";
    cin>>deposits;
    //Add deposits onto the balance
    endBal=begBal+deposits;
    if(checks>endBal){
        //If the amount in checks is more than the total balance the account is overdrawn by the amount check-endBal.
        endBal=checks-endBal;
        cout<<"Your balance is $-"<<endBal<<endl;
        cout<<"You have overdrawn your account so an extra fee of $27.75 has been accessed.\n";
        cout<<"Your new balance is $-";
        //Add extra penalty fee
        endBal+=27.75;
        //Output the endBal
        cout<<endBal<<endl<<endl;
    }else {
       //If check amount is less than balance, then the new balance is endBal-checks.
       cout<<"Your balance is $";
       endBal-=checks;
       //Output balance at the end of the month
       cout<<endBal<<endl<<endl;
    }
    
}

void problem4(){
    //Calculates pay for a worker
    //Declare Variables
    float rate,grsPay;
    int hours;
    //Get inputs
    cout<<"Input your rate of pay per hour in $'s"<<endl<<"$";
    cin>>rate;
    cout<<"Input the amount of hours you worked during the week.\n";
    cin>>hours;
    if(hours>40){
        grsPay=rate*20;
        grsPay+=rate*2*20;
        hours=hours-40;
        grsPay+=rate*3*hours;
    }else if(hours>20&&hours<41){
        grsPay=rate*20;
        hours-=20;
        grsPay+=rate*2*hours;
    }else{
        grsPay=rate*hours;
    }
    cout<<"The weekly pay is = $"<<grsPay<<endl<<endl;
}

void problem5(){
    //isp monthly cost
    //Declare Variables
    int hours;
    char pkg;
    float cost;
    cout<<"Package a costs $29.95 per month for 11 hours access plus $2.75 per hour up to\n"
            <<"22 hours, and $5 per hour for any additional hours."<<endl<<endl;
    cout<<"Package b costs $34.95 per month for 22 hours access plus $1.50 per hour up to\n"
            <<"33 hours, and $2.50 per hour for any additional hours."<<endl<<endl;
    cout<<"Package c costs $39.75 for unlimited access."<<endl<<endl;
    cout<<"Choose which package you want. a, b, or c -> ";
    cin>>pkg;
    if(pkg!='c'){
        cout<<"How many hours do you want?\n";
        cin>>hours;
    }else cout<<"Unlimited Hours!!!!!\n";
    if(pkg=='a'){
        if(hours<=11){
            cost=29.95;
        }else if(hours>11&&hours<23){
            hours-=11;
            cost=29.95+2.75*hours;
        }else if(hours>22){
            hours-=22;
            cost=29.95+(2.75*11)+(5*hours);
        }
    }
    if(pkg=='b'){
        if(hours<=22){
            cost=34.95;
        }else if(hours>22&&hours<34){
            hours-=22;
            cost=34.95+1.50*hours;
        }else if(hours>33){
            hours-=33;
            cost=34.95+(1.50*11)+(2.50*hours);
        }
    }   
    if(pkg=='c'){
        cost=39.75;
    }
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Your monthly bill is = $"<<cost<<endl<<endl;
}

void problem6(){
    int i=1,count=1,a;
    while(count<1501){
        i++;
        a=i;
        while(a%2==0){
            a/=2;
        }while(a%3==0){
            a/=3;
        }while(a%5==0){
            a/=5;
        }
        if(a==1){
            count++;
        }
    }
        cout<<"The 1501st ugly number is = "<<i<<endl<<endl;
        //Exit Stage Right

}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

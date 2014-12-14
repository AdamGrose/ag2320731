/* 
 * File:   main.cpp
 * Author: Adam Grose
 * Created on January 19, 2014, 3:59 
 * Assignment 2 chapter 3
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char answer;
    int choice;
    //loop
    do{
        cout<<"Input 1 to execute Problem 1.\n";
        cout<<"Input 2 to execute Problem 2.\n";
        cout<<"Input 3 to execute Problem 3.\n";
        cout<<"Input 5 to execute Problem 5.\n";
        cout<<"Input 6 to execute Problem 6.\n";
        cout<<"Input 7 to execute Problem 7.\n";
        cout<<"Input 10 to execute Problem 10.\n";
        cout<<"Input 14 to execute Problem 14.\n";
        cout<<"Input 16 to execute Problem 16.\n";
        cout<<"Input 19 to execute Problem 19.\n";
        cin>>choice;
        switch(choice){
            case 1:
                    //Declare Variables
    char p1,p2,ans;
       cout<<"Player 1 - input your choice of r for rock, p for paper, or s for scissors.\n";
       cin>>p1;
       cout<<"Now Player 2 - input your choice.\n";
       cin>>p2;
           if((p1=='r'||p1=='R') && (p2=='r' || p2=='R'))
              cout<<"The Game is a tie!\n";                
           else if ((p1=='r'||p1=='R') && (p2=='p' || p2=='P'))
              cout<<"Player 2 wins. Paper covers Rock!\n";
           else if ((p1=='r'||p1=='R') && (p2=='s' || p2=='S'))
              cout<<"Player 1 wins. Rock smashes Scissors!\n";
           else if ((p1=='p'||p1=='P') && (p2=='r' || p2=='R'))
              cout<<"Player 1 wins. Paper covers Rock!\n";
           else if ((p1=='p'||p1=='P') && (p2=='p' || p2=='P'))
              cout<<"The Game is a tie!\n";                
           else if ((p1=='p'||p1=='P') && (p2=='s' || p2=='S'))
              cout<<"Player 2 wins. Scissors cuts Paper!\n";
           else if ((p1=='s'||p1=='S') && (p2=='r' || p2=='R'))
              cout<<"Player 2 wins. Rock smashes Scissors!\n";
           else if ((p1=='s'||p1=='S') && (p2=='p' || p2=='P'))
              cout<<"Player 1 wins. Scissors cuts Paper!\n";
           else if ((p1=='s'||p1=='S') && (p2=='s' || p2=='S'))
              cout<<"The Game is a tie!\n";
           else
               cout<<"Invalid Inputs.\n";
           
           cout<<"Input a y if you want to play again, and anything else to close\n";
           cin>>ans;
    break;
        case 2:
                //Declare Variables
    float newBlnce,balance,intst,ttlDue,pay;
    //Input Account Balance
    cout<<"Enter your credit card account balance.\n";
    cout<<setprecision(2)<<fixed<<showpoint;
    cin>>balance;
    if(balance>1000){
    newBlnce=balance-1000;
    intst=0.015*1000;
    intst+=0.01*newBlnce;
    ttlDue=balance+intst;
       if(ttlDue<=10){
           pay=ttlDue;
           cout<<"The total Interest due is = $"<<intst<<endl;
           cout<<"The total amount due is   = $"<<ttlDue<<endl;
           cout<<"The minimum payment is    = $"<<pay<<endl;
       }else{
           pay=ttlDue*0.10;
           cout<<"The total Interest due is = $"<<intst<<endl;
           cout<<"The total amount due is   = $"<<ttlDue<<endl;
           cout<<"The minimum payment is    = $"<<pay<<endl;
       }
    
    }else{
        intst=0.015*balance;
        ttlDue=balance+intst;
           if(ttlDue<=10){
           pay=ttlDue;
           cout<<"The total Interest due is = $"<<intst<<endl;
           cout<<"The total amount due is   = $"<<ttlDue<<endl;
           cout<<"The minimum payment is    = $"<<pay<<endl;
       }else{
           pay=ttlDue*0.10;
           cout<<"The total Interest due is = $"<<intst<<endl;
           cout<<"The total amount due is   = $"<<ttlDue<<endl;
           cout<<"The minimum payment is    = $"<<pay<<endl;
       }
    }
    //Exit Stage Right
    break;
            case 3:
                    //Declare Variables
    int brthMth,brthDy;
    //Input birthday
    cout<<"Enter your birthday. First the month 1-12, then the day.\n";
    cin>>brthMth;
    cin>>brthDy;
    //Output horoscope
    if((brthMth==1&&brthDy>=20)||(brthMth==2&&brthDy<=18)){
        cout<<"Your Sign is Aquarius.\n";
   }else if((brthMth==2&&brthDy>=19)||(brthMth==3&&brthDy<=20)){
        cout<<"Your Sign is Pisces.\n";
   }else if((brthMth==3&&brthDy>=21)||(brthMth==4&&brthDy<=19)){
        cout<<"Your Sign is Aries.\n";
   }else if((brthMth==4&&brthDy>=20)||(brthMth==5&&brthDy<=20)){
        cout<<"Your Sign is Taurus.\n";
   }else if((brthMth==5&&brthDy>=21)||(brthMth==6&&brthDy<=21)){
        cout<<"Your Sign is Gemini.\n";
   }else if((brthMth==6&&brthDy>=22)||(brthMth==7&&brthDy<=22)){
        cout<<"Your Sign is Cancer.\n";
   }else if((brthMth==7&&brthDy>=23)||(brthMth==8&&brthDy<=22)){
        cout<<"Your Sign is Leo.\n";
   }else if((brthMth==8&&brthDy>=23)||(brthMth==9&&brthDy<=22)){
        cout<<"Your Sign is Virgo.\n";
   }else if((brthMth==9&&brthDy>=23)||(brthMth==10&&brthDy<=22)){
        cout<<"Your Sign is Libra.\n";
   }else if((brthMth==10&&brthDy>=23)||(brthMth==11&&brthDy<=21)){
        cout<<"Your Sign is Scorpio.\n";
   }else if((brthMth==11&&brthDy>=22)||(brthMth==12&&brthDy<=21)){
        cout<<"Your Sign is Sagittarius.\n";
   }else if((brthMth==12&&brthDy>=22)||(brthMth==1&&brthDy<=19)){
        cout<<"Your Sign is Capricorn.\n";

   }else
       cout<<"Enter a correct birthday.\n";
   break;
            case 5:
                    //Declare Variables
    int hr,min,call;
    float cost;
    char dayPt1,dayPt2;
    cout<<"Input the day of the week the call was made\n";
    cout<<"Enter the first letter and press enter, then the second letter and press enter\n";
    cin>>dayPt1;
    cin>>dayPt2;
    cout<<"Enter the tie the call was made in 24 hour notation\n";
    cout<<"ex: 1:30pm is input as 13 30.\n";
    cin>>hr>>min;
    cout<<"Enter how long the call lasted in minutes\n";
    cin>>call;
    cout<<setprecision(2)<<fixed<<showpoint;
    if((dayPt1=='s'||dayPt1=='S')){
        cost=call*0.15f;
        cout<<"$"<<cost<<endl;
    }else{
        if(hr>8&&hr<18){
            cost=call*0.40f;
            cout<<"The cost of the call is $"<<cost<<endl;
        }else{
            cost=call*0.25f;
            cout<<"The cost of the call is $"<<cost<<endl;
        }
    }
    //Exit Stage Right
    break;
            case 6:
                    //Declare Variables
    float a,b,c;
    float disc,discSq,root1,root2;
    //Input the variables
    cout<<setprecision(7)<<fixed<<showpoint;
    cout<<"Enter three numbers for a,b,and c to find the roots of the equation ax^2+bx+c\n";
    cin>>a>>b>>c;
    //calculate discriminant
    disc=((b*b)-(4*a*c));
    //calculate complex roots
    if (disc<0){
        disc=disc*-1;
        cout<<disc<<endl;
        discSq=sqrt(disc);
        root1=(-1*b+discSq)/(2*a);
        root2=(-1*b-discSq)/(2*a);
        cout<<root1<<"i"<<" or "<<root2<<"i";
    }else{
    //calculate the first root
    discSq=sqrt(disc);
    root1=(-1*b+discSq)/(2*a);
    root2=(-1*b-discSq)/(2*a);
    cout<<root1<<" or "<<root2;
    }
    break;
            case 7:
                    //Declare variables
    unsigned short number;
    char n1000,n100,n10;
    
    //Input the number
    cout<<"conversion to Roman Numerals"<<endl;
    cout<<"Input a number between 1000-3000"<<endl;
    cin>>number;
    
    //Calculations
    n1000=number/1000;
    number-=n1000*1000;
     n100=number/100;
    number-=n100*100;
     n10=number/10;
    number-=n10*10;
 //Output the 1000's
    switch(n1000){
        case 3: cout<<"M";
        case 2: cout<<"M";
        case 1: cout<<"M";
    }
    
     //Output the 100's
    switch(n100){
        case 9: cout<<"CM";break;
        case 8: cout<<"DCCC";break;
        case 7: cout<<"DCC";break;
        case 6: cout<<"DC";break;
        case 5: cout<<"D";break;
        case 4: cout<<"CD";break;    
        case 3: cout<<"C";
        case 2: cout<<"C";
        case 1: cout<<"C";
        default:;
    }
    
         //Output the 10's
    switch(n10){
        case 9: cout<<"XC";break;
        case 8: cout<<"LXXX";break;
        case 7: cout<<"LXX";break;
        case 6: cout<<"LX";break;
        case 5: cout<<"L";break;
        case 4: cout<<"XL";break;    
        case 3: cout<<"X";
        case 2: cout<<"X";
        case 1: cout<<"X";
        default:;
    }
    
            //Output the 1's
    switch(number){
        case 9: cout<<"IX";break;
        case 8: cout<<"VIII";break;
        case 7: cout<<"VII";break;
        case 6: cout<<"VI";break;
        case 5: cout<<"V";break;
        case 4: cout<<"IV";break;    
        case 3: cout<<"I";
        case 2: cout<<"I";
        case 1: cout<<"I";
        default:;
    }
    
    cout<<endl;
    
    //Exit stage right
    break;
            case 10:
                   //Declare variables
    int n;
    int fi;
    int fip1;
    int fip2;
    fi=0;
    fip1=1;
 
    cout<<"enter a positive number greater than 2."<<endl;
    cin>>n;
    
    for(int counter=3;counter<=n;counter++){
        fip2=fip1+fi;
        fi=fip2;
        fip1=fip2;
                
    }
    
    cout<<fip2<<endl;
        //Exit Stage right
    break;
            case 14:
                    //Declare Variables
    bool prime;
    prime= true;

for (int x = 3; x <= 100; x++)
{
    prime = true;
for (int y = 2; y <= (x - 1); y++)
{
    if ((x % y) == 0)
    {
        prime = false;
        break;
    }
}
if (prime == true)
    cout<<x<<endl;
}
    break;
            case 16:
                //Declare Variables
    int fnght;
    int celsius;
    fnght=0;
    celsius=100;
    for(;celsius!=fnght;celsius--){
        fnght=((9*celsius)/5)+32;
    }
    cout<<"Celsius and Fahrenheit are the same at\n";
    cout<<celsius<<" Celsius and"<<endl;
    cout<<fnght<<" Fahrenheit"<<endl;
    break;
            case 19:
                //Declare Variables
    int tthPick=23,plRemov,cpRemov,x;
    do{
        cout<<"Player choose to remove 1,2, or 3 toothpicks from a pile of 23.\n";
        cin>>plRemov;
        tthPick-=plRemov;
        if(tthPick<=0){
            cout<<"Computer wins.\n";
        }
        else if(tthPick>4){
        x=plRemov;
        cpRemov=4-x;
        tthPick-=cpRemov;
        }else if(tthPick>=2&&tthPick<=4){
            tthPick=1;
        }else{
            tthPick=0;
            cout<<"Player wins.\n";
        }          
    }while(tthPick>0);
    break;
    }cout<<"Enter a y if you would like to execute another problem. Anything else to exit.\n";
     cin>>answer;
    }while(answer=='y'||answer=='Y');
    
    return 0;
}


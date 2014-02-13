/* 
 * File:   main.cpp
 * Author: Adam Grose
 * February 11nd, 2014
 * Project 2
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//Global Constants none
const int COLS=7;

//Function Prototypes
void health(int&,int&);//initializes health
void Menu();//simple menu
void move(char &,int);//Takes movement as input
void encScrn();//Encounter Screen
void fieldFill(char [][COLS],int,char,int,int &,int &,int&,int&);//Fills the field array
void print(char [][COLS],int,int&);//Prints out the field and player position
void battleMenu(int,int,int&,int&,int,string);//outputs turn,health,enemy,and attack options
void plDamage(int&,int&,int&,int&,string);//deals damage to computer based on which attack chosen
void attack1(int,int&,string);//Sword attack
void attack2(int,int&,string);//Fire attack
void attack3(int,int&,string);//Flurry attack
int attack4();//Potion
void plAtkScreen(int,string);//Outputs which attack used and how much damage done
void cmpDamage(int&,int&,int&,int&);//Deals damage to player based on which attack chosen
void cmpAtkScreen(int);//outputs which attack used and how much damage done
void winDecide(int,int,int,string,int&,int&);//Outputs who wins
void plWin(int,int,string,int);//player win menu
void cmpWin(int,int,string,int);//computer win menu
void gameWin(int);//Outputs game win screen
void gameLose();//Outputs game lose screen

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS=7;
    char field[ROWS][COLS];
    int plHp,cmpHp,plAtck,cmpAtck,plDamg,cmpDamg,i,count=1,enc,lives=5;
    int up=0,down=0,left=0,right=0,pos,win,numWin=0;
    char ans,choice;
    string name;
    //Initialize random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Get players name
        cout<<"Enter your First name only.\n";
        cin>>name;
    //Game Menu
    Menu();
    cout<<"FIND THE TREASURE!\n"<<endl;
    do{
        move(choice,count);
        fieldFill(field,ROWS,choice,count,up,down,left,right);
        //Set win position
        win=field[rand()%7][rand()%7];
        count++;
        print(field,ROWS,enc);
        if(enc<=15){
                //Enemy Encounter
                encScrn();
                //Initialize turns
                i=1;
                cout<<endl<<endl<<"        A GIANT WOLF ATTACKS"<<endl;
                //Initialize health
                health(plHp,cmpHp);
                //Initialize the battle menu
                do{
                    battleMenu(plHp,cmpHp,plAtck,cmpAtck,i,name);
                    //Calculate and apply damage done by the player
                    plDamage(plAtck,plHp,cmpHp,plDamg,name);
                      //Output the attack and damage caused by the player
                      plAtkScreen(plDamg,name);
                        if(cmpHp>0){
                                //Calculate and apply the damage done by the computer
                                cmpDamage(cmpAtck,cmpHp,plHp,cmpDamg);
                                //Output the attack and damage caused by the computer
                                cmpAtkScreen(cmpDamg);
                                }i++;
                 }while(cmpHp>0&&plHp>0);
    //Output the win screen if the Player won, or if the computer won
    winDecide(plHp,cmpHp,i,name,lives,numWin);
    //re-output screen
    print(field,ROWS,enc);
        }
    }while(lives>0&&win!='X');
    if(win=='X')gameWin(numWin);
    if(lives=0)gameLose();
    //Exit Stage Right
    return 0;
}

void Menu(){
    int dum;
    cout<<"          ARENA    \n";
    cout<<"       BATTLE RPG   \n";
    do{
    cout<<endl<<"Enter 1 to play ";
    cin>>dum;
    cout<<endl;
    if(dum!=1)cout<<"Not a valid input.\n";
    }while(dum!=1);
}

void move(char &choice,int count){
      if(count>1){
                cout<<"Enter direction 'w','s','a', or 'd'"<<endl;
                cin>>choice;
}
}

void fieldFill(char field [][COLS],int ROWS,char choice,int count,int &up,int &down,int &left,int &right){
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            field[row][col]='-';
        }
    }if(count==1){
        field[6][3]='X';
    }if(choice=='w'){
        if((6-up)+down>0){
            up++;
            field[(6-up)+down][(3-left)+right]='X';
        }else{
            field[(6-up)+down][(3-left)+right]='X';
            cout<<"Cannot Go beyond the boundaries."<<endl;
        }
    }if(choice=='s'){
        if((6-up)+down<6){
          down++;
          field[(6+down)-up][(3-left)+right]='X';  
        }else{
           field[(6-up)+down][(3-left)+right]='X';
           cout<<"Cannot Go beyond the boundaries."<<endl; 
        }
    }if(choice=='a'){
        if((3-left)+right>0){
            left++;
            field[(6+down)-up][(3-left)+right]='X';
        }else{
            field[(6-up)+down][(3-left)+right]='X';
            cout<<"Cannot Go beyond the boundaries."<<endl;
        }
    }if(choice=='d'){
        if((3-left)+right<6){
            right++;
            field[(6+down)-up][(3-left)+right]='X';
        }else{
            field[(6-up)+down][(3-left)+right]='X';
            cout<<"Cannot Go beyond the boundaries."<<endl;
        }
    }
}

void print(char field[][COLS],int ROWS,int &enc){
    //print the array and set position
      for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            cout<<field[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    enc=rand()%100+1;
}

void encScrn(){
    int dum;
    cout<<"ENEMY ENCOUNTER!!!\n";
    cout<<"press 1 to continue\n";
    do{
    cin>>dum;
    }while(dum!=1);
}

void health(int& hp1,int& hp2){
    //Computer and player hp initialized to 100
    hp1=100;
    hp2=100;
}

void battleMenu(int hp1,int hp2,int& play,int& wolf,int i,string name){
    //Outputs the players and computers current health
    cout<<name<<" hp "<<hp1<<"%";
    cout<<setw(15)<<"wolf hp "<<hp2<<"%"<<endl;
    //Outputs what turn it currently is
    cout<<"Turn "<<i<<endl;
    cout<<setw(9)<<"          _       \n";
    cout<<setw(9)<<"         / |  __ \n";
    cout<<setw(9)<<"        /__| /_| \n";
    cout<<setw(9)<<"      /_(X)_|__| \n";
    cout<<setw(9)<<"     /________| \n";
    cout<<setw(9)<<"    /_/________| \n";
    cout<<setw(9)<<"    V_________| \n";
    cout<<setw(9)<<"    /_________| \n";
    cout<<setw(9)<<"   /___________| \n";
    cout<<setw(9)<<"  /____________| \n";
    cout<<"                                "<<endl;
    //Output the attack menu
    cout<<"1.)Sword Attack        3.)Flurry"<<endl;
    cout<<"2.)Fire                4.)Potion"<<endl;
    do{
    //Enter a valid attack to continue if not, then player is prompted to input another number.
    cin>>play;
    if(play>4)cout<<"not a valid input.\n";
    }while(play>4||play<=0);
    cout<<endl<<endl;
    wolf=rand()%3+1;
}

void plDamage(int& attack,int& plHp,int& cmpHp,int& damage,string name){
    damage=0;
    switch(attack){
        case 1: {
            //Damage is set to sword attack and computer takes damage
            attack1(attack,damage,name);
            cmpHp-=damage;
            break;
        }
        case 2: {
            //damage is set to fire attack and computer takes damage
            attack2(attack,damage,name);
            cmpHp-=damage;
            break;
        }
        case 3: {
            //damage is set to flurry and computer takes damage
            attack3(attack,damage,name);
            cmpHp-=damage;
            break;
        }
        case 4: {
        //If player health is below 100
        if(plHp<100){
            //temp used to calculate how much hp player has lost
            int temp;
            temp=100-plHp;
            if(temp>20){
                //If player has lost more than 20 hp then player regains 20hp
                cout<<name<<" USED POTION!!!\n";
                cout<<name<<" GAINED 20 HP!!\n"<<endl;
                plHp+=attack4();
                damage=0;
                break;
            }
            else{
                //If player has lost less than 20 hp then player regains full health
                cout<<name<<" USED POTION!!!\n";
                cout<<name<<" GAINED "<<temp<<" HP!!\n"<<endl;
                plHp=100;
                damage=0;
                break;
            }
    }else
        //If player has full hp, then no hp is gained
        cout<<name<<" USED POTION!!!\n";
        cout<<"POTION HAD NO EFFECT!!!\n"<<endl;
        damage=0;
        break;
}
}
}

void attack1(int atck,int& dmg,string name){
    //Standard attack. Does 15 damage
    cout<<name<<" USED SWORD ATTACK\n";
    dmg=15;
}

void attack2(int atck,int& dmg,string name){
    cout<<name<<" USED FIRE\n";
    //Initialize a random number to variable temp
    int temp=rand()%100+1;
    //if temp falls between 1 and 25 or 75 and 100 then the attack is successful
    if((temp<=50)||(temp>=75&&temp<=100)){
    //The fire attack does damage between 20 and 40 and anything
    //above 30 is labeled a critical hit
    dmg=rand()%(40-20)+20;
    if(dmg>=30)cout<<"CRITICAL HIT!!!\n";
}
    else{
    //If temp doesn't fall within range, the attack fails and does no damage
    cout<<"FIRE FAILED!!\n"<<endl;
    
}
}

void attack3(int atck,int& dmg,string name){
    cout<<name<<" USED FLURRY\n";
    int count;
    dmg=0;
    //Initialize loop to repeat attack as long as the random number falls
    //between 1 and 70
    for(int i=0;i<=70;i=rand()%100+1){
        dmg+=5;
        //keeps track of how many attacks were executed
        count++;
    }
    cout<<"ATTACKED "<<count<<" TIMES\n"<<endl;
}
int attack4(){
    //Returns 20 health as an integer
    int incr;
    incr=20;
    return incr;
}

void plAtkScreen(int plDamage,string name){
    int dum;
    if(plDamage>0)cout<<name<<" DEALT "<<plDamage<<" DAMAGE!!!\n"<<endl;
      
}

void cmpDamage(int& attack,int& cmpHp,int& plHp,int& damage){
    int temp;
    damage=0;
    attack=rand()%4+1;
    switch(attack){
        case 1: {
            cout<<"WOLF USED SCRATCH!!!"<<endl;
            damage=10;
            plHp-=damage;
            break;
        }
        case 2: {
            cout<<"WOLF USED BITE!!!"<<endl;
            damage=15;
            plHp-=damage;
            break;
        }
        case 3: {
            cout<<"WOLF USED RAGE!!!"<<endl;
            damage=30;
            plHp-=damage;
            break;
        }
        case 4: {
            if(cmpHp<100){
                temp=100-cmpHp;
                if(temp<=10){
                    cout<<"WOLF LICKED HIS WOUNDS. GAINED "<<temp<<" HP!!!\n"<<endl;
                    damage=0;
                    cmpHp=100;
                    break;
                }else{
                    damage=0;
                    cmpHp+=10;
                    cout<<"WOLF LICKED HIS WOUNDS. GAINED 20 HP!!!\n"<<endl;
                    break;
                }
            }else{
                damage=0;
                cout<<"WOLF LICKED HIS WOUNDS.\n";
                cout<<"LICK HAD NO EFFECT!\n"<<endl;
            }
            break;
        }
    }
}

void cmpAtkScreen(int cmpDamage){
    int dum;
      if(cmpDamage>0)cout<<"WOLF DEALT "<<cmpDamage<<" DAMAGE!!!\n"<<endl;
    do{
    cout<<"Enter 1 to continue ";
    cin>>dum;
    if(dum!=1)cout<<"invalid input\n";
    }while(dum!=1);
}

void winDecide(int plHp,int cmpHp,int i,string name,int &lives,int &numWin){
    if(plHp>0){
        numWin++;
        plWin(i,plHp,name,lives);
    }else{
        lives--;
        cmpWin(i,cmpHp,name,lives);
    }
    
}

void plWin(int i,int plHp,string name,int lives){
    int dum;
    cout<<name<<" hp "<<plHp<<"%";
    cout<<"              wolf hp 0%"<<endl;
    cout<<"                 _/     /   /    \n";
    cout<<"                // |  _/_  /      \n";
    cout<<"               //__| //_| /       \n";
    cout<<"             /_/(X)_|/__|/        \n";
    cout<<"            /_/_____/__|/        \n";
    cout<<"           /_//____/___/_|       \n";
    cout<<"           V/_____/___/_|        \n";
    cout<<"           //____/___/__|         \n";
    cout<<"          //____/___/____|        \n";
    cout<<"         //____/___/_____|        \n"; 
    cout<<"     YOU DEFEATED THE WOLF in "<<i<<" turns.\n";
    cout<<"     You Have "<<lives<<" lives left.\n"<<endl;
    cout<<"Enter 1 to continue \n";
    do{
        cin>>dum;
    }while(dum!=1);
}

void cmpWin(int i,int cmpHp,string name,int lives){
    int dum;
    cout<<name<<" hp 0%";
    cout<<setw(15)<<"wolf hp "<<cmpHp<<"%"<<endl;
    cout<<setw(9)<<"        _       \n";
    cout<<setw(9)<<"       / |  __ \n";
    cout<<setw(9)<<"      /__| /_| \n";
    cout<<setw(9)<<"    /_(X)_|__| \n";
    cout<<setw(9)<<"   /________| \n";
    cout<<setw(9)<<"  /_/________| \n";
    cout<<setw(9)<<"  V_________| \n";
    cout<<setw(9)<<"  /_________| \n";
    cout<<setw(9)<<" /___________| \n";
    cout<<setw(9)<<"/____________| \n";
    cout<<"                                "<<endl;
    cout<<"         YOU LOST in "<<i<<" turns.\n";
    cout<<"     You Have "<<lives<<" lives left.\n"<<endl;
    cout<<"Enter 1 to continue \n";
    do{
        cin>>dum;
    }while(dum!=1);
}

void gameWin(int numWin){
 cout<<setw(3)<<"  ________________"<<endl;
 cout<<setw(3)<<" (_______________)"<<endl;
 cout<<setw(3)<<" |               |"<<endl;  
 cout<<setw(3)<<" |      /|       |"<<endl;  
 cout<<setw(3)<<" |       |       |"<<endl;   
 cout<<setw(3)<<"       __|__     /"<<endl; 
 cout<<setw(3)<<"                / "<<endl;    
 cout<<setw(3)<<"               /  "<<endl; 
 cout<<setw(3)<<"              /   "<<endl;  
 cout<<setw(3)<<"     |       |    "<<endl; 
 cout<<setw(3)<<"     |       |    "<<endl; 
 cout<<setw(3)<<"     |       |    "<<endl; 
 cout<<setw(3)<<"_____|_______|____"<<endl;    
 cout<<endl<<"YOU WIN!!!"<<endl;
 cout<<"You defeated "<<numWin<<" Wolves.";
}

void gameLose(){
    cout<<"YOU LOSE!!!";
}

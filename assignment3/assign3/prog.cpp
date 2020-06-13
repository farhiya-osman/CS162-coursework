#include <iostream>
#include <cstdlib>
#include "zoo.h"

using namespace std;
/******************************************************************* 
 * ** Program: prog.cpp
 * ** Author: Farhiya Osman 
 * ** Date: 05/10/2020
 * ** Description: This program allows you to play zoo tycoon
 * ** output:The money, age, number of animals, and month is printed at the end
 * *******************************************************************/
int main(){
   cout << "Welcome to Zoo Tycoon" << endl; 
   cout << "-----------------------" << endl; 
   zoo z; 
 while(z.get_bankrupt() == false){
    int count = 0; 
       do{
           z.step_one(); 
        if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        }
         cout << "-------------------------------------" << endl; 
        z.special_event(); 
         //z.get_money(); 
        if(z.get_money() <= 0){
           z.set_bankrupt(true); 
           return 0;
        }
         z.purchase_adult();
        if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        }
        z.sell_animal();
        if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        }
        z.foodexp();
        if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        }
         z.revenue(); 
         if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        } 
        z.infoprint();
        if(z.get_money() <= 0){
           z.set_bankrupt(true); 
           return 0;
        }
        int cont;  
        cout << "Would you like to continue ? (1-Yes, 2-No) " << endl; 
        cin>>cont; 
         if(cont == 2){
            return 0; 
         }   
        count ++; 
       }while(count == 0);
    
         z.increase_age();
         z.revenue(); 
         if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        } 
         
         z.special_event();
         if(z.get_money() <= 0){
           z.set_bankrupt(true); 
           return 0;
        } 
         z.purchase_adult();
         if(z.get_money() <= 0){
           z.set_bankrupt(true); 
           return 0;
        }  
         z.sell_animal(); 
         if(z.get_money() <= 0){
           z.set_bankrupt(true);
           return 0; 
        } 
         z.foodexp();
         if(z.get_money() <= 0){
           z.set_bankrupt(true); 
           return 0;
        } 
         z.infoprint();
         int conts;  
         cout << "Would you like to continue ? (1-Yes, 2-No) " << endl; 
         cin>>conts; 
         if(conts == 2){
            return 0; 
         }   
    
 }


cout << "Game over ;(" << endl; 






   /* while(z.get_bankrupt() == false){
       z.gamept2(); 

       if(z.get_money() < 0){
          z.get_bankrupt() == true; 
       } 
   } 
   if(z.get_money() < 0){
      cout << "You have no more money in the bank. " << endl; 
      cout << "Thank you for playing hope to see you again soon. " << endl; 
   }  */

}
#include "restaurant.h"
#include "emp_hours.h"
#include "menu.h"
#include "pizza.h"
#include <iostream>
using namespace std;
/******************************************************************* 
 * ** Program: menu.cpp
 * ** Author: Farhiya Osman 
 * ** Date: 04/26/2020
 * ** Description: This program sorts spe
 * ** output: Sorted spells by effect, page number or average success rate
 * *******************************************************************/
/*******************************************************************
 * ** Function: employee_options
 * ** Description: choices as an employee
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
int  employee_options(){
   cout<< "1.Change hours" << endl; 
   cout<< "2.View Orders" << endl; 
   cout<< "3. Remove orders" << endl; 
   cout<< "4. Add Item to Menu" << endl; 
   cout<< "5. Remove Item from Menu" << endl; 
   cout<< "6. View Menu" << endl; 
   cout<< "7.View Hours" << endl;
   cout<< "8.View Address" << endl; 
   cout<< "9.View Phone" << endl; 
   cout<< "10. Log out"  << endl;
   int choice;  
   cin >>  choice; 
   cout << choice << endl; 

   return choice; 

}
/*******************************************************************
 * ** Function: erroroption
 * ** Description: error handling user option  
 * ** Parameters:int echoice 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool erroroption(int echoice){
    if(echoice >0 && echoice < 11){
      return true;  

   }
   return false; 
}
/*******************************************************************
 * ** Function: erroroption
 * ** Description: error handling user option  
 * ** Parameters:int echoice 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool erroroption2(int coption){
    if(coption >0 && coption < 9){
      return true;  

   }
   return false; 
}
/*******************************************************************
 * ** Function: erroroption
 * ** Description: error handling user option  
 * ** Parameters:int echoice 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool erroroption3(int option){
    if(option >0 && option < 4){
      return true;  

   }
   return false; 
}
/*******************************************************************
 * ** Function: customeroption 
 * ** Description: prints all the options as a customer 
 * ** Parameters:int echoice 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
int  customer_options( ){
   cout<< "1.View Menu" << endl; 
   cout<< "2.Search by cost" << endl; 
   cout<< "3.Search by ingredients" << endl; 
   cout<< "4.Place order" << endl; 
   cout<< "5.View Hours" << endl; 
   cout<< "6. View Address" << endl; 
   cout<< "7.View Phone" << endl;
   cout<< "8. Log out"  << endl;
   int choice;  
   cin >>  choice; 
   cout << choice << endl; 

   return choice; 

}
/*******************************************************************
 * ** Function: coptions 
 * ** Description: cusotmer option 
 * ** Parameters:int echoice 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void copions(int coption){
   Restaurant r; 
   Menu m;
            if(coption == 1){
               r.view_menu();
            }
            else if(coption == 2){
               cout << "What is your maximum budget in dollars: " << endl; 
               int cost;
               cin >> cost; 
               r.search_menu_by_price(cost);
           }
           else if(coption == 3){ // option 3 functions 
              int choice,lookfor;
              string ingred = " ";
              cout << "Would you like to include(1) or exclude(2)?" << endl; 
              cin >> choice; 
              if(choice == 1){
                 cout << "Please enter the ingredients you would like to include " << endl; 
                 cin>> ingred; 
                 r.search_by_ingredients(ingred);
              }
              else if(choice == 2){
               string eingred; 
               cout << "Please enter the ingredients you like to exclude: " << endl; 
               cin>> eingred; 
                //r.search_by_eingredients(eingred);
              }
           }
           else if(coption == 4){
               m.set_menu(); 
               r.place_order(); 
           }
           else if(coption == 5){
              r.set_restaurant_data();// option 5 functions 
               r.view_hours();
           }
           else if(coption == 6){
              r.set_restaurant_data();
               r.view_address();
           }
           else if(coption == 7){ // option 7 functions 
              r.set_restaurant_data();
               r.view_phone();
           }
           else if(coption == 8){
         
           }
}
/*******************************************************************
 * ** Function: eoptions 
 * ** Description: employee options 
 * ** Parameters:int echoice 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void eoptions(int echoice){
   Restaurant r; 
   Menu m;
   int count = 0; 
            if(echoice == 1){  // option 1 functions 
               r.set_restaurant_data();
               r.change_hours();
            }
            else if(echoice == 7){ // option 7 functions 
               r.set_restaurant_data();
               r.view_hours();
            }
            else if(echoice == 6){ // option 6 functions 
               m.set_menu();
               r.view_menu();
            }
            else if(echoice == 8){
               r.set_restaurant_data();
               r.view_address();
            }
            else if(echoice == 9){
               r.set_restaurant_data();
               r.view_phone();
            }
            else if(echoice == 4 ){// option 4 functions 
               r.add_to_menu(); 
            }
            else if(echoice == 2){
               r.view_orders();
            }
            else if(echoice == 3){
               //r.set_pizzarra();
               r.set_orders();
               r.remove_orders();
            }
            else if(echoice == 5){// option 5 functions 
                r.remove_from_menu();
            }
            else if(echoice == 10){
      
            }

}
/*******************************************************************
 * ** Function: int main
 * ** Description:  compiles all aspects of program
 * ** Parameters:
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
int main(int argc, char *argv[])
{
   bool one = false; 
   Restaurant r;
   Pizza p; 
   Menu m;
   int option;
   do{
      cout << " Welcome to Bytes Pizza " << endl; 
      cout << "Are you a customer(1) or employee(2) or would you like to quit(3)? " << endl; 
      cin >> option;
      bool testval2 = erroroption3(option); 
         if(testval2 == 0){
            cout << "invalid option please enter 1 for customer, 2 for employee, and 3 for quit: " << endl; 
            cin >> option; 
         }
      int echoice; 
      if(option == 2){
         r.set_employee_data();
       do{
           one = r.login(); //bool function 
           if(one == false){
             cout << "Error please enter your username and password again: " << endl; 
              one = r.login(); 
            }
         }while(one == false);
      if(one == true){
          int option;
         do{
            echoice = employee_options(); 
            bool testval = erroroption(echoice);
            if(testval == 0){
               cout << "Invalid input please choose a number between 1 and 10: " << endl;  
               cin>> echoice; 
            }
            if(echoice > 0 || echoice < 10){
              eoptions(echoice);
            }
            if(echoice == 10){
               cout << "Logging out: " << "\n" << " Welcome to Bytes Pizza " << "\n" << "Are you a customer(1) or employee(2) or would you like to quit(3)? " << endl; 
               cin >> option;
               if(option == 1){
                 do{ 
                   int coption = customer_options();
                    bool testval = erroroption2(coption);
                    if(testval == 0){
                     cout << "Invalid input please choose a number between 1 and 8: " << endl;  
                     cin>> coption; 
                   }
                   if(testval == 0){
                     cout << "Invalid input please choose a number between 1 and 10: " << endl;  
                     cin>> echoice; 
                  }
                   if(coption > 0 || coption < 8){
                     copions(coption); 
                   }
                    if(coption == 8){
                       cout << "Logging out: " << "\n" << " Welcome to Bytes Pizza " << "\n" << "Are you a customer(1) or employee(2) or would you like to quit(3)? " << endl; 
                        int one3; 
                        cin >> one3; 
                        if(one3 == 3){
                           return 0; 
                        }
                    }
               }while(option !=3); 
            }
            else if (option == 3){
               return 0; 
            }
            }
              
         }while(option != 10 );
      }
        
    }
   else if(option == 1){
          do{ 
            int coption = customer_options();
           bool testval = erroroption2(coption);
            if(testval == 0){
               cout << "Invalid input please choose a number between 1 and 8: " << endl;  
               cin>> coption; 
            }
            if(testval == 0){
               cout << "Invalid input please choose a number between 1 and 10: " << endl;  
               cin>> echoice; 
            }
            if(coption > 0 || coption < 8){
              copions(coption); 
            }
            if(coption == 8){
               cout << "Logging out: " << "\n" << " Welcome to Bytes Pizza " << "\n" << "Are you a customer(1) or employee(2) or would you like to quit(3)? " << endl; 
               cin >> option; 
               if(option == 2){
                  bool two = false; 
                  do{
                        /* do{
                        two = r.login(); //bool function 
                        /* if(two == false){
                           cout << "Error please enter your username and password again: " << endl; 
                           two = r.login(); 
                         } 
                        } while(two == false);  */ 
                         echoice = employee_options(); 
                         bool testval = erroroption(echoice);
                         if(testval == 0){
                        cout << "Invalid input please choose a number between 1 and 10: " << endl;  
                        cin>> echoice; 
                        }
                     if(echoice > 0 || echoice < 10){
                        eoptions(echoice);
                     }
                     if(echoice == 10){
                        cout << "Logging out: " << "\n" << " Welcome to Bytes Pizza " << "\n" << "Are you a customer(1) or employee(2) or would you like to quit(3)? " << endl; 
                        int option2; 
                        cin >> option2;
                        if(option2 == 3){
                           return 0; 
                        }    
                     }
                  }while(option != 3 );

               }
               else if(option == 3){
                     return 0;
                  }
            } 
         }while(option != 3);
         
   }           
   else{
         return 0; 
      }
}while(option !=3); 
	return 0;
}
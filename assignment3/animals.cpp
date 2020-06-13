#include "animals.h"

using namespace std; 
//default constructor 
/*******************************************************************
 * ** Function: animals()
 * ** Description:  default consturctor. Initializes all values  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
animals::animals(){
    age = 0; 
    numbabies = 0; 
    purchasecost = 0.0; 
    feedingcost = 0.0; 
    sellprof = 0.0;    
} 
/*******************************************************************
 * ** Function: animals operator=(animals & z2
 * ** Description:   assignment operator overload 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
animals& animals::operator=(animals & z2){
    return *this;
}
/*******************************************************************
 * ** Function: animals(const animals& z2)
 * ** Description:   copy constructo r
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
animals::animals(const animals& z2){

}
/*******************************************************************
 * ** Function: set_age 
 * ** Description:  sets the age for each animal  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void animals::set_age(int a){
    age = a;
} 
/*******************************************************************
 * ** Function: set_pcost 
 * ** Description:  set the purchase cost of each animal  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/  
void animals::set_pcost(float sc){
    purchasecost = sc; 
}
/*******************************************************************
 * ** Function: set_babynum
 * ** Description: set the number of babies for each animal  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void animals::set_babynum(int b){
   numbabies = b; 
}
/*******************************************************************
 * ** Function: set_foodcost
 * ** Description:   sets the food cost for each animal 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void animals::set_foodcost(float fc){
   feedingcost = (basecost * fc); 
}
/*******************************************************************
 * ** Function: set_Sellprofit
 * ** Description:   sets the selling profit
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void animals::set_sellprofit(float sp){
    sellprof = sp; 
}
/*******************************************************************
 * ** Function: get_age
 * ** Description:  gets the age of each animal  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
int animals::get_age()const{
    return age; 
} 
/*******************************************************************
 * ** Function: get_pcost
 * ** Description:   gets the purchase cost of each animal 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/ 
int animals::get_pcost()const{
    return purchasecost; 
}
/*******************************************************************
 * ** Function: get_babynum
 * ** Description:  gets the numbers of the baby  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
float animals::get_babynum()const{
    return numbabies; 
}
/*******************************************************************
 * ** Function: get_foodcost()
 * ** Description:   returns the food expenses for each animal 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
float animals::get_foodcost()const{
    return feedingcost; 
}
/*******************************************************************
 * ** Function: get_sellingprof
 * ** Description:   returns the selling profit
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
float animals::get_sellingprof()const {
   return sellprof; 
}
/*******************************************************************
 * ** Function: age_calc
 * ** Description:  increases the age of each animal  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void animals::age_calc(){
    age++;
}
/*******************************************************************
 * ** Function: ~animals()
 * ** Description: destructor. Deletes elements in teh array   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
animals::~animals(){

}


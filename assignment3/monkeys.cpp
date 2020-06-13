
#include <iostream>
#include <string> 
#include "monkeys.h"
#include "animals.h"


using namespace std; 
/*******************************************************************
 * ** Function: monkeys
 * ** Description:  default constructor. Iniitalizes the values
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/ 
monkeys::monkeys():animals(){
    age = 1; 
    numbabies = 0; 
    purchasecost = 15000; 
    feedingcost = 4; 
    sellprof = 7500;  
}


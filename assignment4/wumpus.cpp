#include "wumpus.h"

using namespace std; 
/*******************************************************************
 * ** Function: wumpus():events()
 * ** Description:    initializes the  message for the wumpus on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
wumpus::wumpus():event(){
    message = "You smell a terrible stench. ";
}
/*******************************************************************
 * ** Function: get_message()
 * ** Description:  prints the desired message from the wumpus on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
string wumpus::get_message(){
    return message; 
}

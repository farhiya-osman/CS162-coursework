
#include "gold.h"

using namespace std; 
/*******************************************************************
 * ** Function: gold():events()
 * ** Description:    initializes the message on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
gold::gold():event(){
    message = "You see a glimmer nearby" ;
}
/*******************************************************************
 * ** Function: get_message()
 * ** Description:   prints the message on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
string gold::get_message(){
    return message; 
}


#include "bats.h"
#include "event.h"


using namespace std; 
/*******************************************************************
 * ** Function: bats():events()
 * ** Description:    initializes all the points on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/

bats::bats():event(){
  message = "You hear wings flapping " ; 

}
/*******************************************************************
 * ** Function: get_message()
 * ** Description:   prints out the required message when it near the bat room 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
string bats::get_message(){
    return message; 
}

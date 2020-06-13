#include "room.h"
/*******************************************************************
 * ** Function: room()
 * ** Description:    initializes the message on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
room::room(){
     cordx = 0; 
     cordy = 0; 
     events = " "; 
     eventroom = NULL; 
     advent = 1; 
     signal1 = " "; 

} 
/*******************************************************************
 * ** Function: set_eventsnum()
 * ** Description:    sets the reqiuired events of the board  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void room::set_eventsnum(string n){
   events = n;
}
/*******************************************************************
 * ** Function: get_eventsnum()
 * ** Description:  prints out the desired elements on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
string room::get_eventsnum(){
   return events; 
}
/*******************************************************************
 * ** Function: set_roomevent()
 * ** Description:    initializes and creates each aspect of the class 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void room::set_roomevent(int symbl){
   if(symbl == 1){
      eventroom = new wumpus; 
      cout << "w"; 
   }else if(symbl == 2){
      eventroom = new bats;
      cout << "b"; 
   }else if(symbl == 3){
      eventroom = new gold; 
      cout << "g"; 
   }else if(symbl == 4){
      eventroom = new pit; 
      cout << "p"; 
   }
   else{ 
      eventroom = NULL; 
   }
}
/*******************************************************************
 * ** Function: set_adventurer 
 * ** Description:   allows you to print out the required position of the adventurer on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void room::set_adventurer(int a){
    if(a == 1){
      advent = 1 ; 
   }
   else if(a == 2){
      advent = 2;
   }
}
/*******************************************************************
 * ** Function: get_Advent()
 * ** Description:  prints the desired location on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
int room::get_adventure(){
     return advent; 
}
/*******************************************************************
 * ** Function: warningmessage()
 * ** Description: prints the desired message based on each room 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
string room::warningmessage(string b){
   
   signal1 = eventroom->get_message(); 
   return signal1; 
}
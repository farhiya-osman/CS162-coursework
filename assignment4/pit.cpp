
#include "pit.h"

using namespace std; 

pit::pit():event(){
    message = " You feel a breeze  ";
}
string pit::get_message(){
    return message; 
}
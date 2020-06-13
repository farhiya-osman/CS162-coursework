#include "square.h"
#include <iostream>

using namespace std; 

square::square(){
     name = "square"; 
     color = "green"; 
     length = 0; 
}
square::square(float l){
    name = "rectangle"; 
    color = "orange"; 
    length = l; 
}
float square::get_length(){
    return length; 
}
void square::set_length(float l ){
    length = l; 
}
float square::area(){
    return length * length;  
}
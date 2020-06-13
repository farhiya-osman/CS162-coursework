#include "circle.h"
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std; 

circle::circle():shape(){
    name = "circle"; 
    color = "pink"; 
    radius = 0.0;
}
circle::circle(float r):shape(){
    name = "circle"; 
    color = "pink "; 
    radius = r; 
}
void circle::set_radius(float r){
  radius = r; 
}
float circle::get_radius(){
    return radius; 
}
void circle::set_weight(float we){
    weight = we; 
}
float circle::get_weight(){
    return weight; 
}
float circle::area()const{
    float area; 
    area = 3.14 * pow(radius,2); 
    return area;
}

#include "rectangle.h"
#include <iostream> 
#include <cmath>

using namespace std;

rectangle::rectangle():shape(){
    name = "rectangle"; 
    color = "orange"; 
    width = 0.0; 
    height = 0.0; 
   // weight = 0.0; 
}
rectangle::rectangle(float h, float wid):shape(){
    name = "rectangle"; 
    color = "orange"; 
    width = wid;
    height = h;
}
float rectangle::get_width(){
    return width; 

}
float rectangle::get_height(){
    return height; 
    
}
void rectangle::set_width(float wid){
    width = wid; 
}
void rectangle::set_height(float h){
    height = h; 
}
void rectangle::set_weight(float ww){
    weight = ww;
}
float rectangle::get_weight(){
    return weight; 
}
float rectangle::area()const{
    float a; 
    a = width*height; 
    return a; 

}

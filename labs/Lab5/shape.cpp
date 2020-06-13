#include <iostream> 
#include "shape.h"

using namespace std; 

shape::shape(){
    name = " square"; 
    color = " purple"; 

}
bool shape::operator>(const shape&w){
  if(this -> area() > w.area()){
      return true;
  }
  return false; 
}
bool shape::operator<(const shape&w){
     if(this -> area() < w.area()){
      return true;
    }
  return false; 
    
}
string shape::get_name(){
    return name; 
}
string shape::get_color(){
    return color; 
}
void shape::set_name(string n){
    name = n; 
}
void shape::set_color(string c){
    color = c; 
}
void shape::print_shape_info(shape &b){
    cout << b.name << endl; 
    cout << b.color << endl; 
    cout << b.area() << endl; 
 
}
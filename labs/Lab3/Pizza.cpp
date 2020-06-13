

#include <string>
#include <fstream>
#include "pizza.h"

using namespace std;

Pizza::Pizza(){
   name = "Chesse Pizza";
   num_ingredients = 5;
}

void Pizza::set_cost(int,int,int){
  small_cost = 5;
  medium_cost = 8;
  large_cost = 14;
}
string Pizza::get_name() const{
  return name;

}
int Pizza::get_num_ingredients() const{
  return num_ingredients; 

}
void Pizza::set_name(string n){
    name = n ; 
}
void Pizza::set_ingredientsnum(int i ){
     num_ingredients = i ; 
}
 void Pizza::populate_pizza_data( ifstream& menuinput){
   menuinput >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients ;
   ingredients  = new string[num_ingredients];
   for(int i = 0; i<num_ingredients; i++){
     menuinput >> ingredients[i];
   }
 }

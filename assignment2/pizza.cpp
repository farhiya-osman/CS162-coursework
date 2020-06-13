#include <string>
#include <fstream>
#include "pizza.h"

using namespace std;


/*******************************************************************
 * ** Function: Pizza()
 * ** Description: default constructor  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Pizza::Pizza(){ //default constructor 
   name = "empty";
   small_cost = 0;
   medium_cost = 0;
   large_cost= 0;
   num_ingredients = 0;
   ingredients = NULL;
}
//non-default constructor
/*******************************************************************
 * ** Function: Pizza(string name1, int small, int medium, int large, int numingred, string* ingred)
 * ** Description: non-default constructor  
 * ** Parameters: string name1, int small, int medium, int large, int numingred, string* ingred  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Pizza::Pizza(string name1, int small, int medium, int large, int numingred, string* ingred){ 
  name = name1; 
  small_cost = small;
  medium_cost = medium;
  large_cost= large;
  //num_ingredients = numingred;
  ingredients = new string[numingred];
  for(int i = 0; i<numingred; i++){
      ingredients[i] = ingred[i];
  }
}
//copy constructor 
/*******************************************************************
 * ** Function: Pizza(const Pizza& p2)
 * ** Description: copy constructor  
 * ** Parameters:const Pizza& p2
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Pizza::Pizza(const Pizza& p2){
    name = p2.name; 
    small_cost = p2.small_cost;
    medium_cost = p2.medium_cost;
    large_cost = p2.large_cost;
    num_ingredients = p2.num_ingredients;
    //is this correct for an array?
    //if(ingredients == 0 ){
     //   ingredients = NULL; 
    //}
    //else{
    ingredients = new string[num_ingredients];
    for(int i = 0; i<num_ingredients; i++){
      ingredients[i] = p2.ingredients[i];
   // }
    }
}

//assignment operator overload
/*******************************************************************
 * ** Function: Pizza& Pizza::operator= (const Pizza& p2)
 * ** Description: assignment operator overload 
 * ** Parameters:const Pizza& p2
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Pizza& Pizza::operator= (const Pizza& p2){
    name = p2.name; 
    small_cost = p2.small_cost;
    medium_cost = p2.medium_cost;
    large_cost = p2.large_cost;
    num_ingredients = p2.num_ingredients;
    //if(ingredients != NULL){
     //   delete [] ingredients;
   // }
   // if(ingredients == 0){
    //    ingredients = NULL;
    //}
    //else{
       ingredients = new string[num_ingredients];
       for(int i = 0; i<num_ingredients; i++){
         ingredients[i] = p2.ingredients[i];
       }
    //} 
    return *this;
 // how do you deal with the ingredients array
}
//accessors and mutator functions 
/*******************************************************************
 * ** Function: get_name(), get_num_ingredients(),get_smallcost(),get_largecost()
 * ** Description: Accessors function 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: constant
 * *******************************************************************/
string Pizza::get_name() const{ //accessors const 
    return name; 
}
int Pizza::get_num_ingredients() const{
    return num_ingredients; 
}
int Pizza::get_smallcost() const{
    return small_cost;
}
int Pizza::get_mediumcost() const{
    return medium_cost; 
}
int Pizza::get_largecost() const{
    return large_cost;
}
string Pizza::get_ingredients(int p){
    return  ingredients[p]; 
}
/*******************************************************************
 * ** Function: set_name(),set_smallcost(), set_mediumcost, set_largecost
 * ** Description: mutator functions 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Pizza::set_name(string n){ //mutator functions below
    name = n; 
}
void Pizza::set_smallcost(int small){
    small_cost = small; 
}
void Pizza::set_mediumcost(int medium){
    medium_cost = medium; 
}
void Pizza::set_largecost(int large){
    large_cost = large; 
}
void Pizza::set_ingredientsnum(int numingred ){
    num_ingredients = numingred; 
}
void Pizza::set_ingredientsarr(string* ingred ){
    ingredients = ingred; 
}

/*******************************************************************
 * ** Function::populate_pizza_data(ifstream& menuinput)
 * ** Description: reads in the values from the menu text file
 * ** Parameters:none 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Pizza::populate_pizza_data(ifstream& menuinput){ //reading the file into the program
   menuinput >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients ; // no loop because only reading one line of code not all info. 
   if(ingredients == NULL){
   ingredients  = new string[num_ingredients];
   }
   for(int i = 0; i<num_ingredients; i++){
     menuinput >> ingredients[i];
   }
 }
 /*******************************************************************
 * ** Function: ~Pizza
 * ** Description: destructor deletes the arrays allocated in the class 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
 Pizza::~Pizza(){ // destructors 
    delete [] ingredients ; 
}
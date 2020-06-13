#include <string>
#include <iostream>
#include <fstream>
#include "pizza.h"


using namespace std;

int main(){
   Pizza p; 
   ifstream menuinput; 
   int menusize; 
   menuinput.open("menu.txt");
   if(menuinput.is_open()){
      menuinput >> menusize; 
      p.populate_pizza_data(menuinput);
   }
   
   cout << p.get_name() << endl; 
   cout << p.get_num_ingredients() << endl; 

   p.set_name("veggie_pizza");
   p.set_ingredientsnum(10);

   cout << p.get_name() << endl; 
   cout << p.get_num_ingredients() << endl; 
}
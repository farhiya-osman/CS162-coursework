#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>

using namespace std;

class Pizza {
  private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string* ingredients;
  
  public:
    Pizza();
    string get_name() const;
    void set_name(string);
    void set_cost(int,int,int);
    void set_ingredientsnum(int); 
    int get_num_ingredients() const;
    void populate_pizza_data(ifstream& );
    

    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
};





#endif
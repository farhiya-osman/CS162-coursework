#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>
#include "rectangle.h"
#include "shape.h"

using namespace std; 
class square : public rectangle{
  private: 
   float length; 
  public: 
  square(); 
  square(float); 
  float area(); 
  float get_length(); 
  void set_length(float); 


};

#endif
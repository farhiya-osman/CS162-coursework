#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string> 
#include "shape.h"
using namespace std; 

class circle : public shape {
  private:
     float radius;
public:
    circle();
    circle(float); 
    void set_radius(float); 
    float get_radius(); 
    float area()const; 
    void set_weight(float); 
    float get_weight(); 
};

#endif
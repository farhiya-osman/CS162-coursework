#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string> 
#include "shape.h"
using namespace std; 

class rectangle : public shape{
private:
    float width;
     float height;
     //float weight; 
public:
    rectangle(); 
    rectangle(float,float);
    float get_width(); 
    float get_height(); 
    void set_width(float);
    void set_height(float); 
    void set_weight(float); 
    float get_weight(); 
    float area()const; 
};
#endif
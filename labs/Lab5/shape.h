#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

using namespace std; 

class shape{
protected:
     string name;
     string color;
     float weight; 
public:
    shape(); 
    string get_name(); 
    string get_color(); 
    void set_name(string); 
    void set_color(string); 
    bool operator>(const shape&w); 
    bool operator<(const shape&w);
    virtual float area()const = 0;  
    void print_shape_info(shape &b); 
    
};
#endif
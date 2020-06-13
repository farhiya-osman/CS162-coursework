#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std; 

int main(){
    //shape s;
    rectangle r;
    circle c;
    square e;  
    r.set_height(7); 
    r.set_width(3); 
    c.set_radius(7);
    //e.set_length(5); 
    r.set_name("rectangle"); 
    r.area(); 
    c.set_name("circle"); 
    c.area(); 

        
  /*   cout << "The name of the shape " << s.get_name() << endl; 
    cout << "The color of the shape is " << r.get_color() << endl; 
    cout << "The area of the rectangle: " << r.area() << endl; 
    cout << "The area of the circle: " << c.area_cal() <<endl; 
    cout << "The area of the square: " << e.area() << endl;  */
   /*  cout << "This is a " << r.get_name() << " and my area is " << r.area() << endl; 
    cout << "This is a " << c.get_name() << " and my area is " << c.area() << endl; 
    if(r > c){
        cout << "The rectangle has a larger area than the circle " << endl; 
    }
    if(r < c){
        cout << "The rectangle has a smaller area  than the circle " << endl; 
    } */
    e.print_shape_info(r) ; 
    

}
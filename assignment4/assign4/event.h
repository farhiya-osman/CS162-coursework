#ifndef EVENT_H
#define EVENT_H

#include <iostream>


using namespace std;

class event {
  private:
     string message; 
    

  public:
   event(); 
   virtual string get_message() = 0 ;  

};

#endif
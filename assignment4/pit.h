#ifndef PIT_H
#define PIT_H

#include <iostream>
#include "event.h"

using namespace std;

class pit : public event {
  private:
     string message; 
  public:
  pit(); 
   string get_message(); 
   
   

};

#endif
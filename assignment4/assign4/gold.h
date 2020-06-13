#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"

using namespace std;

class gold : public event{
  private:
     string message; 
  public:
   gold(); 
   string get_message(); 

};

#endif
#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include "event.h"

using namespace std;

class wumpus : public event {
  private:
     string message; 
  public:
  wumpus(); 
   string get_message(); 
   

};

#endif
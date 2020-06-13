#ifndef BATS_H
#define BATS_H

#include <iostream>
#include "event.h"

using namespace std;

class bats : public event {
  private:
    string message; 
  public:
   bats(); 
   string get_message(); 

};

#endif
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string> 
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

using namespace std;

class room {
  protected: 
    int cordx; 
    int cordy; 
    string events ; 
    int advent; 
    event *eventroom; 
    string signal1; 
    bats * bat; 

  public:
    room(); 
    bool adve(bool); 
    void set_eventsnum(string); 
    string get_eventsnum();   
    void set_roomevent(int); 
    void set_adventurer(int); 
    int get_adventure(); 
    string warningmessage(string ); 
};

#endif
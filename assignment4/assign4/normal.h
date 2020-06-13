#ifndef NORMAL_H
#define NORMAL_H


#include "event.h"
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include <iostream>
#include <vector>
#include <cmath> 
#include <stdlib.h>


using namespace std;

class normal {
  protected:
    vector<vector<room> >vec; 
    bool gameover; 
    bool adventuretracker; 
    int eventnum;
    int arrow; 
    int initialy,initialx;
    int initial_x,initial_y; 
    int adventurposx,adventurposy;
    int wumpusposx,wumpusposy; 
    int batposx,batposy;
    int goldposx,goldposy; 
    int pitposx,pitposy; 
    int gsize; 
    bool wumpustracker; 
    bool goldtracker; 
    bool wincondition; 
    bool pitdeath; 
  public:
  normal(); 
  normal(int); 
  void directions(); 
  void gameplan(); 
  void print_message(); 
  void shoot_arrow(); 
  string warning(string); 
  void print_board(int);    
  void update_board(int); 
  int random_placementy(); 
  void set_board(); 
  void adventurer_direction(); 
  bool is_alive(); 
  void wumpus_room(); 
  void bats_room(); 
  void pits_room(); 
  void room_check(); 
  void encounter(); 
  void encounters(); 
  void encountere(); 
  void encounterw(); 
  void bats_rooms(); 
  void bats_roome(); 
  void bats_roomw(); 
  bool game_over();  
  bool pit_death(); 
  
   
};

#endif
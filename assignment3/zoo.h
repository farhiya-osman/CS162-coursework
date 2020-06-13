#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 #include "animals.h"
#include "monkeys.h"
#include "seaotter.h"
#include "sloth.h"
#include "tiger.h" 


using namespace std;

class zoo{
  private:
     int day; 
    float dailyfoodcost; 
    int money;
    int bonus; 
    bool bankrupt; 
    monkeys * monkey; 
    seaotter * seaotters; 
    sloth * sloths; 
    tiger * tigers; 
    int num_monkey; 
    int num_seaotter; 
    int num_sloth;  
    int num_tiger; 
    
  public:
     zoo(); 
     void addm(); 
    void addm2();
    void set_bankrupt(bool); 
    void add_tiger(); 
    void sick_tiger(); 
    void tiger_babie(); 
    void purchase_Tiger(); 
    void remove_tiger(); 
    float get_money();
    const zoo&  operator = (const zoo&); 
    void special_event();
    void animal_sick(); 
    void sick_monkey();
    void sick_seaotter();
    void sick_sloth(); 
    void add_monkey();
    void add_sloth(); 
    void add_seaotter();  
    void start(); 
    void day_increase(); 
    zoo( int d, int daycost, int m, int b, int nm, int ns, int nsl); 
    zoo(const zoo& z1) ; 
    void foodexp(); 
    void monkeyrev(); 
    void babies(); 
    void monkeybabie(); 
    monkeys* get_monkey(int)const; 
    sloth*  get_sloth(int)const; 
    seaotter* get_seaotter(int)const;
    tiger * get_tiger(int)const; 
    void purchase_adult(); 
    void purchase_amount(); 
    void purchase_amountsea(); 
    void purchase_amountsloth(); 
    void sell_animal(); 
    void remove_monkey(); 
    void remove_sloth(); 
    void remove_seaotter(); 
    void foodcost(); 
    void step_one(); 
    void increase_age(); 
    void revenue(); 
    bool get_bankrupt(); 
    void bankruptcheck(); 
    void infoprint(); 
    void gamept2(); 
    void slothbabie(); 
    void seaotterbabie(); 
    

    ~zoo(); 

    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
 
};

#endif
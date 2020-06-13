#ifndef  ANIMALS_H 
#define ANIMALS_H 

#include <string>
#include <iostream>


using namespace std;

class animals{
  protected:
   int age; 
   int numbabies; 
    int basecost ; 
   float purchasecost; 
   float feedingcost; 
   float sellprof; 
   
  public:
        animals(); 
        animals& operator=(animals& z2);
        animals(const animals& z2); 
        ~animals();
        int get_age()const;
        int get_pcost()const;
        float get_babynum()const; 
        float get_foodcost()const;
        float get_sellingprof()const;
      

        void set_age(int a);
        void set_pcost(float sc);
        void set_babynum(int b);
        void set_foodcost(float fc);
        void set_sellprofit(float sp); 
        void age_calc(); 
         

  

    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate

    // 
};

#endif
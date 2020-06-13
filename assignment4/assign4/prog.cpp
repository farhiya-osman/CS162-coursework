#include <iostream> 
#include <stdlib.h>
#include <vector> 
#include "runboard.h"
#include "normal.h"
#include "room.h"

using namespace std; 

int main( int argc, char*argv []){
    
    int bsize = atoi(argv[1]); 
    string mode = argv[2];
    room c; 
    if(bsize < 4){
        cout << "The size of the board is to small. Please recomplile and enter a value equal to or greater than 4 " << endl; 
        return 0; 
    }
    if(argc != 3){
        cout << "invalid number of command line arguments. Please recomplile and enter 2 command line arguments " << endl; 
       return 0; 
    } 
    if(mode == "true" || mode == "false"){
    cout << " Welcome to hunt the Wumpus!!! " << endl; 
        if(mode == "true")
        {
            runboard r(bsize);
            //r.gameplan();
            r.set_board(); 
            r.print_board(bsize); 
            do{
                r.update_board(bsize); 
                r.print_message(); 
                r.directions(); 
            }while(r.game_over() == true && r.is_alive() == false );  
        }

        if(mode == "false"){
            normal n(bsize);
            //r.gameplan();
            n.set_board(); 
            n.print_board(bsize); 
            do{
                n.update_board(bsize);
                //n.print_board(bsize);  
                n.print_message(); 
                n.directions(); 
            }while(n.game_over() == true && n.is_alive() == false ); 

        }
    }else{
        cout << "Invalid command line argument. Please recomplie and enter an integer greater than four and true or false" << endl; 
        return 0;
    }
          
    
   
  //  int arrow = 3; 
   // r.runboard(bsize); 
    //runboard r(bsize); 
    //r.shoot_arrow(); 
    //r.gameplan(); 
   // r.directions(arrow); 
    //r.shoot_arrow(arrow);
    //r.set_board(); 
    //r.print_board(bsize); 
    //r.near_event();
    //r.set_rooms(bsize); 
    //r.update_board(bsize); 
    //r.random_placement(bsize); 
    //r.set_rooms(bsize); 
    //r.place_rooms(bsize); 
    //r.update_board(bsize); 
    



}
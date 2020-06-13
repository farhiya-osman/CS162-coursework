#include "normal.h"


using namespace std; 

/*******************************************************************
 * ** Function: normal
 * ** Description:  default consturctor. Initializes all values  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
normal::normal(){
    gameover = true; 
    eventnum = 0; 
    arrow = 3; 
    initial_x = 0; 
    initial_y = 0; 
    adventurposx = 0; 
    adventurposy= 0; 
    gsize = 0; 
    wumpusposx = 0; 
    wumpusposy = 0; 
    batposx,batposy = 0;
    goldposx,goldposy = 0; 
    pitposx,pitposy = 0; 
    initialx = 0; 
    initialy = 0;
    wumpustracker = false; 
    adventuretracker = false; 
    goldtracker = false;
    wincondition = true; 
    pitdeath = true; 
}
/*******************************************************************
 * ** Function: normal(int bsize)
 * ** Description:    initializes all the points 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
normal::normal(int bsize){ //initialize array with command line arguments as the size 
       gsize = bsize; 
      vec.resize(bsize, vector<room>(bsize)); 
      arrow = 3; 
      wumpusposx = 0; 
      wumpusposy = 0; 
}
/*******************************************************************
 * ** Function: print_board()
 * ** Description:    prints the board with only the adventures mark present 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::print_board(int bsize){
  int count = 0; 
  room b;
  for(int i = 0; i<gsize; i++){
    for(int p = 0; p<gsize; p++){
       if(vec[i][p].get_adventure() == 2){
        cout << "|" << "x" ;
      }
      else if(vec[i][p].get_adventure() == 1){
        cout << "|" << " " ; 
      } 
    }
   cout<< endl; 
}
 for(int i = 0; i< gsize; i++){
   cout << "__" ; 
 }
 cout << endl; 
}
/*******************************************************************
 * ** Function: gameplan()
 * ** Description:   Tester function for my game  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::gameplan(){ 
  int counter = 0; 
   set_board(); 
   cout << " Original board with only adventurer present!" << endl; 
   print_board(gsize); 
   cout << endl; 
   cout << "Debugged mode!" << endl; 
  do{
    
   update_board(gsize); 
   print_message(); 
   //directions(arrow); 
   //update_board(gsize);
   //is_alive(); 
   counter++;
  }while(counter < 9); 
}
/*******************************************************************
 * ** Function: print_message()
 * ** Description:  virtual inherits to print messages when you are adjacent to a room  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::print_message(){
    if(adventurposx+1 < gsize && vec[(adventurposx +1)][adventurposy].get_eventsnum() != " " ){
     cout << warning(vec[adventurposx +1][adventurposy].get_eventsnum()) << endl;;     
    }
    if(adventurposx - 1 >=0 && vec[(adventurposx -1)][adventurposy].get_eventsnum() != " " ){
      cout<< warning(vec[adventurposx -1][adventurposy].get_eventsnum()) << endl;  
    }
    if(adventurposy+1 < gsize && vec[(adventurposx )][adventurposy+1].get_eventsnum() != " " ){
      cout << warning(vec[adventurposx][adventurposy+1].get_eventsnum()) << endl; 
    }
    if(adventurposy -1 >=0 && vec[adventurposx][adventurposy -1].get_eventsnum() != " " ){
      cout << warning(vec[adventurposx][adventurposy-1].get_eventsnum()) << endl;  
    }
}
/*******************************************************************
 * ** Function: 
 * ** Description:    
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::directions(){
  int option; 
  cout << "Would you like to shoot an arrow(1)or move your adventurer(2)? " << endl; 
  cin >> option; 
  cin.ignore();
  if(option == 1){
    if(arrow == 0 ){
      cout << "You dont have any more arrows to shoot." << endl; 
      option == 2; 
    }
    else{
      shoot_arrow(); 
    }
  }
  else if(option == 2){
    cout << "call moving adventurer function" << endl; 
    adventurer_direction(); 
  }
}
/*******************************************************************
 * ** Function: encounterw
 * ** Description:  When you enter a room with an animal in it these are the adventurers reaction  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::encounter(){
  if(vec[adventurposx-1][adventurposy].get_eventsnum() != " "){
   string nchar = vec[adventurposx-1][adventurposy].get_eventsnum(); 
   if(nchar == "p" ){ //called when you enter a room with bottomless pits inside 
      cout << "Message: You have entered the bottomless pits " << endl; 
      cout << "    The adventurer has died   " << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposx = adventurposx - 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      gameover = false; 
      goldtracker = true;
      pitdeath = false; 
       cout << "game over :(" << endl;
   }
   else if( nchar == "w"){ //called when you enter a room with wumpus inside 
     cout << "You have entered a room with the wumpus. It has woken up and you have died" << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposx = adventurposx - 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      gameover = false; 
   }
   else if(nchar == "b"){ //called when you enter a room with super bats inside 
     //cout << "hello" << endl; 
     bats_room(); 
   }
   else if(nchar == "g"){ //called when you enter a function with gold inside 
     cout << "You have found the gold!" << endl; 
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposx = adventurposx - 1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     goldtracker = true; 
   }
  }
}
/*******************************************************************
 * ** Function: encounterw
 * ** Description:  When you enter a room with an animal in it these are the adventurers reaction  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::encounters(){
   if(vec[adventurposx+1][adventurposy].get_eventsnum() != " "){ //called when you enter a function with bottomless pits inside 
   string nchar = vec[adventurposx+1][adventurposy].get_eventsnum(); 
   if(nchar == "p" ){
      cout << "Message: You have entered the bottomless pits " << endl; 
      cout << "    The adventurer has died   " << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposx = adventurposx + 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      goldtracker = true;
      gameover = false; 
      pitdeath = false; 
      cout << "game over :(" << endl;
   }
   else if( nchar == "w"){ //called when you enter a function with wumpus inside 
     cout << "You have entered a room with the wumpus. It has woken up and you have died" << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposx = adventurposx + 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
   }
   else if(nchar == "b"){  //called when you enter a room with bats inside 
     //cout << "hello" << endl; 
     bats_rooms(); 
   }
   else if(nchar == "g"){ // called when you enter a room with gold inside 
     cout << "You have found the gold!" << endl; 
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposx = adventurposx + 1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     goldtracker = true; 
   }
  }
}
/*******************************************************************
 * ** Function: encounterw
 * ** Description:  When you enter a room with an animal in it these are the adventurers reaction  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::encountere(){
   if(vec[adventurposx][adventurposy+1].get_eventsnum() != " "){ //enters a room with the bottomless pits 
   string nchar = vec[adventurposx][adventurposy+1].get_eventsnum(); 
   if(nchar == "p" ){
      cout << "Message: You have entered the bottomless pits " << endl; 
      cout << "    The adventurer has died   " << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposy = adventurposy + 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      gameover = false; 
      goldtracker = true;
      pitdeath = false; 
       cout << "game over :(" << endl;
   }
   else if( nchar == "w"){ //enters a room with the wumpus inside 
     cout << "You have entered a room with the wumpus. It has woken up and you have died" << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposy= adventurposy + 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      gameover = false; 
   }
   else if(nchar == "b"){ //enters a room with super bats 
     //cout << "hello" << endl; 
     bats_roome(); 
   }
   else if(nchar == "g"){ //Enters a room with gold 
     cout << "You have found the gold!" << endl; 
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposy = adventurposy + 1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     goldtracker = true; 
   }
  }
}
/*******************************************************************
 * ** Function: encounterw
 * ** Description:  When you enter a room with an animal in it these are the adventurers reaction  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::encounterw(){
 if(vec[adventurposx][adventurposy-1].get_eventsnum() != " "){
   string nchar = vec[adventurposx][adventurposy-1].get_eventsnum(); 
   if(nchar == "p" ){ //enters a room with bottomless pits 
      cout << "Message: You have entered the bottomless pits " << endl; 
      cout << "    The adventurer has died   " << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposy = adventurposy - 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      goldtracker = true;
      gameover = false; 
      pitdeath = false; 
       cout << "game over :(" << endl;
   }
   else if( nchar == "w"){ //enters a room with a wumpus 
     cout << "You have entered a room with the wumpus. It has woken up and you have died" << endl; 
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposy = adventurposy - 1; 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      adventuretracker = true; 
      gameover = false; 
   }
   else if(nchar == "b"){ //enter a room filled with superbats 
    // cout << "hello" << endl; 
     bats_roomw(); 
   }
   else if(nchar == "g"){ //enters a room and finds the gold 
     cout << "You have found the gold!" << endl; 
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposy = adventurposy - 1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     goldtracker = true;
   }
  }
}
/*******************************************************************
 * ** Function: bats_roomw
 * ** Description:    relocats the adventurer if it enters a room with super bats 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::bats_room(){
     cout << "You've entered the room with super bats! " << endl; //relocating the adventurer randomly if it enters the room with super bats
     int randval = rand() % gsize; 
     int randval1 = rand() % gsize; 
     vec[adventurposx-1][adventurposy].set_eventsnum(" ");
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposx = randval; 
     adventurposy = randval1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     cout << "    The Adventurer has been relocated" << endl;
}
/*******************************************************************
 * ** Function: bats_roomw
 * ** Description:    relocats the adventurer if it enters a room with super bats 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::bats_roome(){
     cout << "You've entered the room with super bats! " << endl; //relocating the adventurer randomly if it enters the room with super bats
     int randval = rand() % gsize; 
     int randval1 = rand() % gsize; 
     vec[adventurposx][adventurposy+1].set_eventsnum(" ");
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposx = randval; 
     adventurposy = randval1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     cout << "   The Adventurer has been relocated" << endl;
}
/*******************************************************************
 * ** Function: bats_roomw
 * ** Description:    relocats the adventurer if it enters a room with super bats 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::bats_rooms(){
     cout << "You've entered the room with super bats! " << endl; //relocating the adventurer randomly if it enters the room with super bats
     int randval = rand() % gsize; 
     int randval1 = rand() % gsize; 
     vec[adventurposx+1][adventurposy].set_eventsnum(" ");
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposx = randval; 
     adventurposy = randval1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     cout << "   The Adventurer has been relocated" << endl;
}
/*******************************************************************
 * ** Function: bats_roomw
 * ** Description:    relocats the adventurer if it enters a room with super bats 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::bats_roomw(){
    cout << "You've entered the room with super bats! " << endl; //relocating the adventurer randomly if it enters the room with super bats
     int randval = rand() % gsize; 
     int randval1 = rand() % gsize; 
     vec[adventurposx][adventurposy-1].set_eventsnum(" ");
     vec[adventurposx][adventurposy].set_eventsnum(" "); 
     adventurposx = randval; 
     adventurposy = randval1; 
     vec[adventurposx][adventurposy].set_eventsnum("x"); 
     cout << "   The Adventurer has been relocated" << endl;
}
string normal::warning(string b){
   bats bs; 
   pit ps; 
   gold g; 
   wumpus ws; 
   string signal1; 
   if(b == "p"){
      signal1 = ps.get_message(); 
   }
   else if(b == "b"){
      signal1 =  bs.get_message(); 
   }
   else if(b == "w"){
      signal1 = ws.get_message(); 
   }
   else if(b== "g"){
      signal1 = g.get_message(); 
   } 
   return signal1; 

}
/*******************************************************************
 * ** Function: wumpus_room
 * ** Description: Function call that reacts when you enter a room with a wumpus in it   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::wumpus_room(){
  if(vec[adventurposx][adventurposy].get_eventsnum() == "w"){
    cout << " You have entered the room with the wumpus " << endl; 
    wumpustracker = true; 
  }
}
/*******************************************************************
 * ** Function: adventurer_direction
 * ** Description:  moves the adventurer within the board to the desired location   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::adventurer_direction(){
  string achoice; 
  cout << "What direction would you like to move in the tunnel " << endl; 
  cout << " w-North " << " s-South " << " d-East " << " a-West " << endl; 
  getline(cin,achoice); 
  //cin.ignore(); 
  /*  if(achoice != "w" && achoice != "s" && achoice != "d" && achoice != "a"){
     cout << "Please enter a valid direction w,s,d,a. " << endl; 
     cout << " w-North " << " s-South " << " d-East " << " a-West " << endl;
     getline(cin,achoice); 
     //cin.ignore(); 
   } */
  if(achoice == "w" ){ //move the adventurer north
    if((adventurposx - 1) >= gsize -1 ){
      cout << " Unable to move North. Outside of range. " << endl; 
    }
    else{
      cout << "Moving adventure north! " << endl;
      if(vec[adventurposx -1][adventurposy].get_eventsnum() != " "){
        encounter(); 
      }
      else{
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposx = (adventurposx -1); 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
      }
    }
  }
  else if(achoice == "s"){ //moving the adventurer south
    if((adventurposx +1) >  gsize-1 ){
      cout << "Unable to move South. Outside of range. " << endl; 
    }
    else{
      cout << "Moving adventure south! " << endl;
      if(vec[adventurposx + 1][adventurposy].get_eventsnum() != " "){
        encounters(); 
      }
      else{
      vec[adventurposx][adventurposy].set_eventsnum(" ");
      adventurposx = (adventurposx +1); 
      vec[adventurposx][adventurposy].set_eventsnum("x");
      }
    }
  }
  else if(achoice == "d"){ //moving the adventurer east 
    int updatepos = (adventurposy + 1) ; 
    int updateboard = gsize; 
    if(updatepos >= updateboard){
        cout << "Out of range! Unable to move east " << endl; 
      }
    else{ 
      if(vec[adventurposx][adventurposy+1].get_eventsnum() != " "){
          encountere(); 
      }
      else{
        cout << "Moving adventure east! " << endl;
        vec[adventurposx][adventurposy].set_eventsnum(" "); 
        adventurposy = (adventurposy +1); 
        vec[adventurposx][adventurposy].set_eventsnum("x");
    }
    }
  }
  else if (achoice == "a"){ //moving the adventurer west
    if((adventurposy -1) < 0 ){
      cout << "Out of range!! Unable to move west. " << endl; 
    }
    else{
      if(vec[adventurposx][adventurposy-1].get_eventsnum() != " "){
        encounterw(); 
      }
      else{
      cout << "Moving adventure west! " << endl;
      vec[adventurposx][adventurposy].set_eventsnum(" "); 
      adventurposy = (adventurposy -1); 
      vec[adventurposx][adventurposy].set_eventsnum("x"); 
    }
    }
  } 
}
/*******************************************************************
 * ** Function: shoot_arrow
 * ** Description:  Shoots an arrow in the indicated direction  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::shoot_arrow(){
  string choice; 
  cout << "Press space then enter in the direciton of the arrow" << endl; 
  cout << " w-North " << " s-South " << " d-East " << " a-West " << endl; 
  cin.clear(); 
  cin.ignore(); 
  getline(cin,choice);
  int arrowx,arrowy,arrowx1,arrowx3; 
  int arrowx2,arrowy1,arrowy2,arrowy3;
  arrowx=arrowx1=arrowx2=arrowx3 = adventurposx;
  arrowy=arrowy1=arrowy2= arrowy3 = adventurposy;
  if(choice != "w" || choice != "s" || choice != "d" || choice != "a" ){ //error handling arrow shooting function 
    cout << "please enter a valid direction with a space. " << endl; 
    getline(cin,choice); 
  }
  if(choice == " w" ){ //shooting an arrow north
    cout << "Your arrow has been shot north! " << endl;
    arrowx1 = (arrowx-2);
    arrowx2 = (arrowx -1);
    arrowx3 = (arrowx-3); 
  }
  else if(choice == " s" ){ //shooting an arrow south
    cout << "Your arrow has been shot South! " << endl; 
    arrowx1 = (arrowx+2);
    arrowx2 = (arrowx +1);
    arrowx3 = (arrowx+3); 
  }
  else if (choice == " d" ){ //shooting an arrow east 
    cout << "Your arrow has been shot East! " << endl; 
    arrowy3 = (arrowy+3); 
    arrowy1 = (arrowy +2); 
    arrowy2 = (arrowy +1);

  }
  else if(choice == " a" ){ //shooting an arrow west 
    cout << "Your arrow has been shot West! " << endl; 
    arrowy1 = (arrowy -2); 
    arrowy2 = (arrowy -1);
    arrowy3 = (arrowy-3); 
  }
  
  if(wumpusposx == arrowx3 && wumpusposy == arrowy3 ){ //wumpus dies scenario 
    cout << "The wumpus is dead." << endl; 
    wumpustracker = true; 
     gameover = false; 
     vec[wumpusposx][wumpusposy].set_eventsnum(" "); 
     wumpusposx = adventurposx; 
     wumpusposy = adventurposy; 
     vec[adventurposx][adventurposy].set_eventsnum("x");
  }
  if(wumpusposx == arrowx1 && wumpusposy == arrowy1 ){ //wumpus dies scenario 
    cout << "The wumpus is dead." << endl; 
    wumpustracker = true;
     gameover = false; 
    vec[wumpusposx][wumpusposy].set_eventsnum(" "); 
    wumpusposx = adventurposx; 
    wumpusposy = adventurposy; 
    vec[adventurposx][adventurposy].set_eventsnum("x");
  }
  if(wumpusposy == arrowy2 && wumpusposx == arrowx2 ){ //wumpus dies scenario 
    cout << "The wumpus is dead." << endl; 
    wumpustracker = true; 
    gameover = false; 
    vec[wumpusposx][wumpusposy].set_eventsnum(" "); 
     wumpusposx = adventurposx; 
     wumpusposy = adventurposy; 
     vec[adventurposx][adventurposy].set_eventsnum("x");
  }
 arrow = (arrow -1);
 cout << "You have " << arrow << " arrows remaining" << endl;  // updating the number of arrows you have remaining
 int rands  =  rand() % 10; 
 if(wumpustracker == false && rands == 1 || rands == 2 || rands ==3 || rands ==4 ){
   cout << "The wumpes has woken up from an arrow being fired. " << endl; 
   int randval = rand()%gsize; 
   if(gameover== true && vec[randval][randval].get_eventsnum() == " "){
     vec[wumpusposx][wumpusposy].set_eventsnum(" "); 
     wumpusposx = randval; 
     wumpusposy = randval; 
     vec[wumpusposx][wumpusposy].set_eventsnum("w"); 
     cout << "The Wumpus has been relocated" << endl;
   }
 }
}
/*******************************************************************
 * ** Function: set_board 
 * ** Description:    initializes all the points on the board 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::set_board(){
  srand(time(NULL)); 
  int rand1,rand2; 
   int randval = rand()%gsize + 1;
  for(int l = 0; l<1; l++){ //adventurer
    int rand1s = rand() % gsize;  //randomizes a position for the adventurer on the grid 
    int rand2s = rand() % gsize; 
    if(vec[rand1s][rand2s].get_eventsnum() == " "){
       vec[rand1s][rand2s].set_eventsnum("x"); 
    }
  }
   for(int l = 0; l<1; l++){ //wumpus 
    int rand1b = rand() % gsize;  //randomizes places withint he grid for the wumpus 
    int rand2b = rand() % gsize; 
    //cout << rand1 << " wumpus " << rand2 << endl; 
    if(vec[rand1b][rand2b].get_eventsnum() == " "){
       vec[rand1b][rand2b].set_eventsnum("w"); 
    }
  }
   for(int l = 0; l<1; l++){ //gold  
    int rand1c = rand() % gsize;  //randomizes places within the grid for the gold 
    int rand2c = rand() % gsize; 
   // cout << rand1 << " gold " << rand2 << endl; 
    if(vec[rand1c][rand2c].get_eventsnum() == " "){
       vec[rand1c][rand2c].set_eventsnum("g"); 
    }
  }
  for(int k = 0; k<1; k++){ //bottomless pits 
    rand1 = rand() % gsize;  //randomizes values for places within the grid 
    rand2 = rand() % gsize; 
    int rand3 = rand() % gsize; 
    int rand4 = rand() % gsize;  
    int randomh = (rand() % 2) + 1; 
    if(randomh == 1 ){
      //cout << rand1 << " bats " << rand2 << endl; 
       if(vec[rand1][rand2].get_eventsnum() == " "){ //randomly places the bats 
       vec[rand1][rand2].set_eventsnum("b");
       vec[rand3][rand4].set_eventsnum("b");   
       }
    }
    else{  //pits
    // cout << rand1 << " pits " << rand2 << endl; 
      if(vec[rand1][rand2].get_eventsnum() == " "){ //randomly places the pits 
       vec[rand1][rand2].set_eventsnum("p"); 
       vec[rand3][rand4].set_eventsnum("p"); 
    }
  }
  for(int i = 0; i<gsize; i++){ //initializes the adventurers starting position
    for(int l = 0; l<gsize; l++){
       if(vec[i][l].get_eventsnum() == "x"){
          initial_x = i;
          initial_y = l;
         // cout << initial_x << " and  " << initial_y << endl; 
          adventurposx = i;
          adventurposy = l;
         // cout << adventurposx << "another one " << adventurposy << endl; 
          vec[i][l].set_adventurer(2);  
       }
       else if(vec[i][l].get_eventsnum() == "b"){ //initializes the bats 
         vec[i][l].set_eventsnum("b"); 
         
       }
       else if(vec[i][l].get_eventsnum() == "w"){ //initializes wumpus 
         vec[i][l].set_eventsnum("w"); 
         initialx = i;
         initialy = l; 
         wumpusposx = i; 
         wumpusposy = l; 
       }
       else if(vec[i][l].get_eventsnum() == "g"){ //initialies the gold 
         vec[i][l].set_eventsnum("g"); 
         goldposx = i; 
         goldposy = l; 
       }
       else if(vec[i][l].get_eventsnum() == "p"){ //initializes the bottomless pits 
         vec[i][l].set_eventsnum("p"); 
         pitposx = i; 
         pitposy = l; 
       }
       else{
         vec[i][l].set_eventsnum(" "); //initializes the empty space within the board 
       }
    }
  }
}
}
/*******************************************************************
 * ** Function: update_board 
 * ** Description:  prints and updated board after the user moves   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void normal::update_board(int bsize){
  cout << endl; 
   for(int i = 0; i<bsize; i++){
    for(int l = 0; l<bsize; l++){
        if(vec[i][l].get_eventsnum() == "x"){
          cout << "|" << "x" ;  
        }
        else{
            cout << "|" << " "; 
        }
       
    }
    cout << endl; 
  }
  for(int i = 0; i<gsize ; i++){
     cout << "__"; 
   } 
   cout << endl;  

}
/*******************************************************************
 * ** Function: is_alive
 * ** Description:    bool function that determines when the user wins the game. 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool normal::is_alive(){
  return goldtracker; 

}
/*******************************************************************
 * ** Function: game_over 
 * ** Description:  determines when the adventurer wins the game   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool normal::game_over(){
   return gameover ; 
}


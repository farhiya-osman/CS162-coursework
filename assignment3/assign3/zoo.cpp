#include <iostream>
#include <cmath>
#include <cstdlib>
#include "zoo.h"

using namespace std; 

//default constructor
/*******************************************************************
 * ** Function: zoo
 * ** Description:  default constructor. Iniitalizes the values
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/ 
 zoo:: zoo(){
    day = 1; 
    dailyfoodcost = 0; 
    money = 50000;
    bonus =  0; 
    bankrupt = false; 
    num_monkey = 0; 
    num_sloth = 0; 
    num_seaotter = 0; 
    num_tiger = 0; 
    monkey = NULL; 
    sloths = NULL;
    seaotters = NULL; 
    tigers = NULL; 
}
/*******************************************************************
 * ** Function: zoo
 * ** Description: non-default constructor 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
zoo::zoo( int d, int daycost, int m, int b, int nm, int ns, int nsl){ 
} 
/*******************************************************************
 * ** Function: zoo
 * ** Description:  copy constructor  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
zoo::zoo(const zoo& z1){
    
}
/*******************************************************************
 * ** Function: get_monkey 
 * ** Description:  gets the monkey array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
monkeys* zoo::get_monkey(int i ) const{
    return &monkey[i]; 
}
/*******************************************************************
 * ** Function: get_sloth
 * ** Description:  gets the sloth array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
sloth* zoo::get_sloth(int p)const{
    return &sloths[p]; 
}
/*******************************************************************
 * ** Function: get_seaotter
 * ** Description:  gets the seaotter array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
seaotter* zoo::get_seaotter(int l)const{
    return &seaotters[l]; 
}
/*******************************************************************
 * ** Function: get_tiger
 * ** Description:  gets the tiger array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
tiger * zoo::get_tiger(int z)const{
    return &tigers[z]; 
}
/*******************************************************************
 * ** Function: zoo& zoo::operator= (const zoo& z2 )
 * ** Description:  assignment overload operator 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
const zoo& zoo::operator= (const zoo& z2 ){
   
    return *this;   
    
}
/*******************************************************************
 * ** Function: get_money 
 * ** Description:  allows you to access the money  value 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
float zoo::get_money(){
    return money; 
}
/*******************************************************************
 * ** Function: get_bankrupt
 * ** Description:  allows you to access the bankrupt value 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool zoo::get_bankrupt(){
    return bankrupt; 
}
/*******************************************************************
 * ** Function: step_one
 * ** Description:  initailizes the game 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::step_one(){
    get_money(); 
cout << "Money in the bank: " << money  << endl; 
    cout << "To begin please enter which species you would like to purchase. You may buy up one adult animal of a single species." << endl; 
    cout<< "monkeys(1)" << "\n" << "sloths(2)" << "\n" << "seaotter(3)" << "\n" << "tiger(4)" << endl ; 
    int animalchoice, numchoice; 
    cin >> animalchoice; 
    if(animalchoice > 4 ){
        cout << "invalid entry please select 1,2 or 3 " << endl; 
        cin >> animalchoice; 
    }
    if(animalchoice == 1 ){ 
         add_monkey(); 
         monkey[num_monkey - 1].set_age(24); 

    }
    else if(animalchoice == 2 ){
         add_sloth();
    }
    else if(animalchoice == 3 ){
         add_seaotter();
    }
    else if(animalchoice == 4){
        add_tiger();
    }
   if(money <= 0){
       set_bankrupt(true); 
   }

}
/*******************************************************************
 * ** Function: start
 * ** Description:  orders the game in the game flow order  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::start(){
    step_one(); 
    get_money(); 
    cout << "-------------------------------------" << endl; 
    special_event(); 
    purchase_adult(); 
    sell_animal(); 
    foodexp();
    infoprint();   
    
}
/*******************************************************************
 * ** Function: set_bankrupt
 * ** Description: determines if you have ran out of money 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::set_bankrupt(bool br){
  if(br == false){
      bankrupt = false;
  }
  if(br == true){
      bankrupt = true; 
  }
}
/*******************************************************************
 * ** Function:gamept
 * ** Description: loops the entire game 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::gamept2(){
    int count = 0; 
    do{
        start(); 
        count++;  
    }while(count ==0); 
         increase_age();
         revenue(); 
         special_event(); 
         purchase_adult(); 
         sell_animal(); 
         foodexp();
         infoprint(); 

}
/*******************************************************************
 * ** Function: infoprint
 * ** Description:  prints out all info by month 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::infoprint(){
    int mad = 0; 
    int sad = 0;
    int sea = 0; 
    int cont; 
     for(int i = 0; i< num_monkey; i++){
        if( monkey[i].get_age() <= 6){
            mad++;
        }
    }
    for(int i = 0; i< num_sloth; i++){
        if (sloths[i].get_age() <= 6){
            sad++; 
        }  
    }
    for(int i = 0; i < num_seaotter; i++){
        if(seaotters[i].get_age() <= 6){
            sea++; 
        } 
    }
    cout << "Month "  << day <<  " recap: " << endl; 
    cout <<"\t" << "Money in bank: " << money << endl;
    cout << "\t" <<"You currently have " << num_monkey << " monkey's " << endl;  
    cout << "\t" <<"You currently have " << num_sloth << "  sloth's " << endl;
    cout << "\t" << "You currently have " << num_seaotter  << " seaotter " << endl; 
    cout << "-------------------------------------------" << endl; 
    cout << "-------------------------------------------" << endl;
    day++;
    cout << "Its about to be month: " << day << endl; 
}
/*******************************************************************
 * ** Function: revenue 
 * ** Description:  calculating the revenue by adding to the money in the bank
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::revenue(){
    if(num_monkey > 0){
        for(int i = 0; i<num_monkey; i++){
            if(monkey[i].get_age() <= 6){
                money += 3000;
            }
            else{
                money +=1500; 
            }
        }
    }
     if(num_sloth > 0){
        for(int i = 0; i<num_sloth; i++){
            if(sloths[i].get_age() <= 6){
                money += 200;
            }
            else{
                money +=100; 
            }
        }
    }
     if(num_seaotter > 0){
        for(int i = 0; i<num_seaotter; i++){
            if(seaotters[i].get_age() <= 6){
                money += 500;
            }
            else{
                money +=250; 
            }
        }
    }
    if(num_tiger > 0){
        for(int i = 0; i<num_tiger; i++){
            if(tigers[i].get_age() <= 6){
                money += 480;
            }
            else{
                money +=240; 
            }
        }
    }
    cout << "----------------------------------------" << endl; 
    cout << "Welcome to a new month " << endl; 
   cout << "After revenue calculations you have " << money << " in the bank" << endl; 
}
/*******************************************************************
 * ** Function: increase_age()
 * ** Description: increases all elements in the array by one month  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::increase_age(){
    for(int i = 0; i< num_monkey; i++){
        int agenew = monkey[i].get_age() + 1; 
        monkey[i].set_age(agenew); 
    }
    for(int i = 0; i< num_sloth; i++){
        int agenew = sloths[i].get_age() + 1; 
        sloths[i].set_age(agenew); 
    }
    for(int i = 0; i < num_seaotter; i++){
        int agenew = seaotters[i].get_age() + 1; 
        seaotters[i].set_age(agenew); 
    }
}
/*******************************************************************
 * ** Function: sell_animal
 * ** Description:  determines which animals to sell 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::sell_animal(){
    int option,sello;
    cout << "Would you like to sell an animal?(1-Yes,2-No)"<< endl; 
    cin >> option; 
    if(option > 2){
        cout << "invalid entry. Please select 1 or 2 " << endl; 
        cin >> option; 
    }
    if(option == 1){
        cout<< "Which animal would you like to sell? A monkey(1),seaotter(2), sloth(3), or tiger(4)" << endl; 
        cin>> sello; 
        if(sello > 4){
        cout << "invalid entry. Please select 1,2,3,4 " << endl; 
        cin >> sello; 
    }
        if(sello ==  1){
            remove_monkey(); 
        }
        else if(sello == 2){
            remove_seaotter(); 
        }
        else if(sello == 3){
            remove_sloth(); 
        }
        else if(sello == 4){
            remove_tiger(); 
        }
    }
    else if(option == 2){
        cout << "The owner decided not to sell an animal.  " << endl;
    }
}
/*******************************************************************
 * ** Function: purchase_adult
 * ** Description: determines which animal to purchase and how many to  purchase 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::purchase_adult(){
    int pchoice,achoice;
    cout << "Would you like to purchase an animals-(1-Yes or 2-No): " << endl; 
    cin >> pchoice; 
    if(pchoice > 2){
        cout << "Invalid choice. Please enter 1 or 2 " << endl; 
        cin >> pchoice; 
    }
    if(pchoice == 1){
            cout << "You may buy up to two adult animals of a single species " << endl; 
            cout << "Would you like to buy a monkey(1), sloth(2), seaotter(3), or tiger(4) " << endl; 
            cin>> achoice;
            if(achoice>4){
                 cout << "Invalid entry. Please enter 1,2,3,4 " << endl; 
                cin>> achoice; 
             } 
                if(achoice == 1){
                    purchase_amount();
                }
                else if(achoice == 2){
                    purchase_amountsloth();
                }
                else if(achoice == 3){
                    purchase_amountsea(); 
                }
                else if(achoice == 4){
                    purchase_Tiger();
                }
    }
    else if(pchoice == 2){
        cout << "No new animal purchases have been made. " << endl; 
    }
}
/*******************************************************************
 * ** Function: purchase_amount
 * ** Description:  Add a monkey to the monkey array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::purchase_amount(){
    cout << "How many would you like to purchase( 1 or 2)" << endl; 
    int p;  
    cin >> p ;
    if(p >2){
        cout << "Invalid entry. Please enter 1 or 2 " << endl; 
        cin>> p; 
    } 
    if(p == 1){
        add_monkey();
    }
    else{
       addm();
       addm2();  
     
    }
}
/*******************************************************************
 * ** Function: aadm()
 * ** Description:  Add a monkey to the monkey array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::addm(){
    monkeys * subs = new monkeys[num_monkey + 1];
    for(int i = 0; i< num_monkey; i++){
        subs[i] = monkey[i];
    } 
    monkeys m; 
    subs[num_monkey] = m; 
    if(monkey != NULL){
        delete [] monkey;
    }
    monkey = subs;
    monkey[num_monkey]; 
    num_monkey++;
    money -= 15000;
    cout << "You have bought a new monkey. You currently have " << num_monkey << " monkeys and you have " << money << " in the bank" <<endl; 
}
/*******************************************************************
 * ** Function: aadm2()
 * ** Description:  Add a monkey to the monkey array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::addm2(){
    monkeys * subs = new monkeys[num_monkey + 1];
    for(int i = 0; i< num_monkey; i++){
        subs[i] = monkey[i];
    } 
    monkeys m; 
    subs[num_monkey] = m; 
    if(monkey != NULL){
        delete [] monkey;
    }
    monkey = subs;
    monkey[num_monkey]; 
    num_monkey++;
    money -= 15000;
    cout << "You have bought a new monkey. You currently have " << num_monkey << " monkeys and you have " << money << " in the bank" <<endl; 
}
/*******************************************************************
 * ** Function: purchase_amountsea
 * ** Description: adds a seaotter to the array by calling add_seaotter  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::purchase_amountsea(){
    cout << "How many would you like to purchase( 1 or 2)" << endl; 
    int choice; 
    cin >> choice ; 
    if(choice>2){
        cout << "Invalid entry. Please enter 1 or 2 " << endl; 
        cin>> choice; 
    } 
    if(choice == 1){
        add_seaotter(); 
    }
    else if(choice == 2){
        add_seaotter(); 
        add_seaotter(); 
    }
}
/*******************************************************************
 * ** Function: purchase_tiger
 * ** Description:  adds a tiger to the tiger array by calling add tiger 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::purchase_Tiger(){
     cout << "How many would you like to purchase( 1 or 2)" << endl; 
    int choice; 
    cin >> choice ; 
    if(choice>2){
        cout << "Invalid entry. Please enter 1 or 2 " << endl; 
        cin>> choice; 
    } 
    if(choice == 1){
        add_tiger(); 
    }
    else if(choice == 2){
        add_tiger(); 
        add_tiger(); 
    }

}
/*******************************************************************
 * ** Function: purchase_amounsloth
 * ** Description:  adds an additional sloth to the array by calling add_sloth
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::purchase_amountsloth(){
    cout << "How many would you like to purchase( 1 or 2)" << endl; 
    int choice; 
    cin >> choice ; 
    if(choice >2){
        cout << "Invalid entry. Please enter 1 or 2 " << endl; 
        cin>> choice; 
    } 
    if(choice == 1){
        add_sloth(); 
    }
    else if(choice == 2){
        add_sloth(); 
        add_sloth(); 
    }
}
/*******************************************************************
 * ** Function: add_monkey 
 * ** Description: Adds a monkey to the monkey array and increases the total number of monkeys by 1
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::add_monkey(){
    monkeys * subs = new monkeys[num_monkey + 1];
    for(int i = 0; i< num_monkey; i++){
        subs[i] = monkey[i];
    } 
    monkeys m; 
    subs[num_monkey] = m; 
    if(monkey != NULL){
        delete [] monkey;
    }
    monkey = subs;
    monkey[num_monkey]; 
    num_monkey++;
    money -= 15000;
    cout << "You have bought a new monkey. You currently have " << num_monkey << " monkeys and you have " << money << " in the bank" <<endl;  
}
/*******************************************************************
 * ** Function: add_tiger 
 * ** Description:  Adds a tiger to the tiger array and increases the whole count of tigers 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::add_tiger(){
    tiger * subs = new tiger[num_tiger + 1];
    for(int i = 0; i< num_tiger; i++){
        subs[i] = tigers[i];
    } 
    tiger t; 
    subs[num_tiger] = t; 
    if(tigers != NULL){
        delete [] tigers;
    }
    tigers = subs;
    tigers[num_tiger]; 
    num_tiger++;
    money -= 2400;
    cout << "You have bought a new tiger. You currently have " << num_tiger << " tigers and you have " << money << " in the bank" <<endl; 

}
/*******************************************************************
 * ** Function: add_sloth
 * ** Description: adds a sloth to the sloth array and to the total count of sloths 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::add_sloth(){
    sloth * subs1 = new sloth[num_sloth + 1];
    for(int i = 0; i< num_sloth; i++){
        subs1[i] = sloths[i];
    } 
    sloth s; 
    subs1[num_sloth] = s; 
    if(sloths != NULL){
        delete [] sloths;
    }
    sloths = subs1;
    num_sloth++;
    money -= 2000; 
    cout << "You have bought a new sloth. You currently have  " << num_sloth << " sloths and you have " << money << " in the bank" <<endl; 
}
/*******************************************************************
 * ** Function: add_seaotter
 * ** Description:  adds a seaotter to the seaotter array and increase the total count of seaotters
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::add_seaotter(){
    seaotter * subs2 = new seaotter[num_seaotter + 1];
    for(int i = 0; i< num_seaotter; i++){
        subs2[i] = seaotters[i];
    } 
    seaotter se; 
    subs2[num_seaotter] = se; 
    if(seaotters != NULL){
        delete [] seaotters;
    }
    seaotters = subs2;
    num_seaotter++;
    money -= 5000; 
    cout << "You have bought a new seaotter. You have  " << num_seaotter << " seaotters and you have " << money << " in the bank" <<endl; 
}
/*******************************************************************
 * ** Function: remove_monkey 
 * ** Description:  removes a monkey from the monkey array and deducts a monkey from the total count
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::remove_monkey(){
 if(num_monkey > 0){
    monkeys * subs = new monkeys[num_monkey - 1];
    for(int i = 0; i< num_monkey; i++){
        subs[i] = monkey[i];
    } 
    monkeys m; 
    subs[num_monkey] = m; 
    if(monkey != NULL){
        delete [] monkey;
    }
    monkey = subs;
    monkey[num_monkey]; 
    num_monkey--;
    money += 7500;
    cout << "You have sold a monkey you currently have  " << num_monkey << " and you have " << money << " in the bank" <<endl; 
 } else{
     cout << "You have no monkeys therefore you cannot sell a monkey " << endl; 
 }
}
/*******************************************************************
 * ** Function: remove_tiger
 * ** Description:  removes a tiger from the tiger array and deducts it from the total number of tigers 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::remove_tiger(){
    if(num_tiger > 0){
    tiger * subs = new tiger[num_tiger - 1];
    for(int i = 0; i< num_tiger; i++){
        subs[i] = tigers[i];
    } 
    tiger ms; 
    subs[num_tiger] = ms; 
    if(tigers != NULL){
        delete [] tigers;
    }
    tigers = subs;
    tigers[num_tiger]; 
    num_tiger--;
    money += 2400;
    cout << "You have sold a tiger you currently have  " << num_tiger << " and you have " << money << " in the bank" <<endl; 
 } else{
     cout << "You have no monkeys therefore you cannot sell a tiger " << endl; 
 } 
}
/*******************************************************************
 * ** Function: remove_sloth
 * ** Description:  removes a sloth from the sloth array and deducts it from the total number of sloths
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::remove_sloth(){
 if(num_sloth > 0){
    sloth * subs1 = new sloth[num_sloth - 1];
    for(int i = 0; i< num_sloth; i++){
        subs1[i] = sloths[i];
    } 
    sloth s; 
    subs1[num_sloth] = s; 
    if(sloths != NULL){
        delete [] sloths;
    }
    sloths = subs1;
    num_sloth--;
    money += 1000 ; 
    cout << "You have sold a  sloth. You currently have  " << num_sloth << " sloths and you have " << money << " in the bank" <<endl;
 }else{
     cout << "You currently have no sloths. Therefore you cannot sell a sloth" << endl; 
 }
}
/*******************************************************************
 * ** Function: remove_Seaotter
 * ** Description:removes a seaotter from the seaotter array   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::remove_seaotter(){
if(num_seaotter > 0 ){
    seaotter * subs2 = new seaotter[num_seaotter - 1];
    for(int i = 0; i< num_seaotter; i++){
        subs2[i] = seaotters[i];
    } 
    seaotter se; 
    subs2[num_seaotter] = se; 
    if(seaotters != NULL){
        delete [] seaotters;
    }
    seaotters = subs2;
    num_seaotter--;
    money += 2500; 
    cout << "You have sold a seaotter. You have  " << num_seaotter << " seaotters and you have " << money << " in the bank" <<endl; 
 }else{
     cout << "You have no seaotters so you cannot sell a seaotter. "<< endl; 
 }
}
/*******************************************************************
 * ** Function: special_event 
 * ** Description: Determines which special event is occuring in the month 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::special_event(){
    cout << "A special event is occuring " << endl; 
    int option ; 
    srand(time(NULL)); 
    option = (rand()%4)+1;
    if(option == 1){
        animal_sick(); 
    }
    else if(option == 2){
        babies();
      //randomly choosen species gives birth function
    }
    else if(option == 3){
        monkeyrev(); 
     //boom in attendence randomly choosen revenue increase between 300-700
    }
    else if(option == 4){
        cout << "No special event occurred during this month" << endl; 
        //nothing happens the game continues 
    }
}
/*******************************************************************
 * ** Function: animal sick 
 * ** Description: randomizes whihc animal gets sick 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::animal_sick(){
   srand(time(NULL)); 
    int sick ; 
    sick = (rand() % 5) + 1;  
    if(sick == 1){
      sick_monkey(); 
    }
    else if(sick ==2){
        sick_seaotter(); 
    }
    else if(sick ==3){
        sick_sloth(); 
    }
    else if(sick == 4){
        sick_tiger(); 
    }
}
/*******************************************************************
 * ** Function: sick_tiger 
 * ** Description: If enough money is in the bank it saves the tiger if not  a monkey dies and is removed from the tiger array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::sick_tiger(){
    if(num_tiger > 0){
        if(money > 1200){
             monkey[num_monkey]; 
            money = (money - 1200); 
            cout << "The monkey will survive, you have " << num_monkey << " at the zoo and " << money << " in the bank" << endl;  
        }
        else{
            monkey[num_monkey]; 
            num_monkey --; 
            cout <<"I'm sadden to inform you that we have lost a monkey. You currently have " << num_monkey << " and " << money << " in the bank" << endl; 
        //remove a monkey from the number of monkey the zoo has
        }
    //} 
}else{
    cout << "You currently have No monkeys. Therefore no monkeys in the zoo got sick." << endl; 
}
 if(money <= 0){
       set_bankrupt(true); 
   }

}
/*******************************************************************
 * ** Function: sick_monkey 
 * ** Description: If enough money is in the bank it saves the monkey if not  a monkey dies and is removed from the monkey array 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::sick_monkey(){
if(num_monkey > 0){
        if(money > 7500){
             monkey[num_monkey]; 
            money = (money - 7500); 
            cout << "The monkey will survive, you have " << num_monkey << " at the zoo and " << money << " in the bank" << endl;  
        }
        else{
            monkey[num_monkey]; 
            num_monkey --; 
            cout <<"I'm sadden to inform you that we have lost a monkey. You currently have " << num_monkey << " and " << money << " in the bank" << endl; 
        //remove a monkey from the number of monkey the zoo has
        }

}else{
    cout << "You currently have No monkeys. Therefore no monkeys in the zoo got sick." << endl; 
}
 if(money <= 0){
       set_bankrupt(true); 
   }
}
/*******************************************************************
 * ** Function: babie
 * ** Description: randomizes which animal is giving birth to a baby
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::babies(){
    srand(time(NULL));
    int birth = (rand() % 5) + 1;  
    if(birth == 1){
      monkeybabie(); 
    }
    else if(birth == 2){
        slothbabie(); 
    } 
    else if(birth == 3){
        seaotterbabie(); 
    }
    else if(birth == 4){
      tiger_babie(); 
    }
}
/*******************************************************************
 * ** Function: tiger_babie
 * ** Description: A new tiger baby is being added to the tiger array and the zoo.    
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::tiger_babie(){
       int count = 0; 
     for(int i = 0; i<num_tiger; i++){
         if(tigers[i].get_age() >= 24){ 
             add_tiger(); 
             tigers[num_tiger-1].set_age(0);
           cout << "Congrats a new Tiger  was born! " << endl; 
           count = 1; 
         }
     }
     if(count != 1){
         cout << "No Tigers are old enough to have kids yet" << endl;
     }

}
/*******************************************************************
 * ** Function: monkeybabie
 * ** Description: Adds a new babie to the zoo and the monkey array   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::monkeybabie(){
    int count = 0; 
     for(int i = 0; i<num_monkey; i++){
         if(monkey[i].get_age() >= 24){ 
             add_monkey(); 
             monkey[num_monkey-1].set_age(0);
           cout << "Congrats a new baby monkey was born! " << endl; 
           count = 1; 
         }
     }
     if(count != 1){
         cout << "No monkeys are old enough to have kids yet" << endl;
     }
}
/*******************************************************************
 * ** Function: slothbabie
 * ** Description: Adds a sloth to the array of age 0-6 months 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::slothbabie(){
    int count = 0; 
     for(int i = 0; i<num_sloth; i++){
         if(sloths[i].get_age() >= 24){ 
            for(int l = 0; l < 5 ; l++){
               add_sloth(); 
               sloths[num_sloth-1].set_age(0);
            }
           cout << "Congrats a 5 new sloths were born! " << endl; 
           count = 1; 
         }
     }
     if(count != 1){
         cout << "No sloths are old enough to have kids yet" << endl;
     }
}
/*******************************************************************
 * ** Function: seaotter babies 
 * ** Description: produces a  new seaotter baby in the zoo.   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::seaotterbabie(){
    int count = 0; 
     for(int i = 0; i<num_seaotter; i++){
         if(seaotters[i].get_age() >= 24){ 
            for(int l = 0; l < 2 ; l++){
               add_seaotter(); 
               seaotters[num_seaotter-1].set_age(0);
            }
           cout << "Congrats a 2 new seaotters were born! " << endl; 
           count = 1; 
         }
     }
     if(count != 1){
         cout << "No seaotters are old enough to have kids yet" << endl;
     }
}
/*******************************************************************
 * ** Function: sick_Seaotter()
 * ** Description:Determine if they can rescue the seaotter or it passes away. Based on money in the bank    
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::sick_seaotter(){
    //call money function 
if(num_seaotter > 0){
    get_money(); 
        if(money > 2500){
            seaotters[num_seaotter]; 
            money = (money - 2500);
            cout << "The seaotter survived, you have " << num_seaotter << " and you have " << money << " in the bank" << endl; 
        }
        else{
            num_seaotter--; 
            seaotters[num_seaotter-1]; 
            cout <<"I'm sadden to inform you that we have lost a seaotter. You currently have " << num_seaotter << " and you have " << money << " in the bank" << endl; 
        }
}else{
    cout << "You have no seaotters in the zoo. Therefore no seaotters got sick " << endl; 
}
  if(money <= 0){
       set_bankrupt(true); 
   }
}
/*******************************************************************
 * ** Function: sick_sloth
 * ** Description:  if the owner has enough money in the bank they can save the sloth if not it is removed
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::sick_sloth(){
    get_money(); 
if(num_sloth > 0){
        if(money > 1000){
            sloths[num_sloth]; 
            money = (money - 1000);
            cout << "The sloth survived, you have " << num_sloth << " and " << money << " in the bank " << endl; 
        }
        else{
            sloths[num_sloth-1] ; 
            num_sloth--; 
            cout <<"I'm sadden to inform you that we have lost a sloth. You currently have " << num_sloth << " and " << money << " in the bank" << endl; 
        }
  
}else{
    cout << "You have no sloths in the zoo. Therefore no sloths got sick " << endl; 
}
  if(money <= 0){
       set_bankrupt(true); 
   }
}
/*******************************************************************
 * ** Function: monkeyrev
 * ** Description:  randomized special event with a boom in revenue 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void zoo::monkeyrev(){
    if(num_monkey > 0){
        srand(time(NULL)); 
        int val = (rand()%200)+100; 
        int total = (num_monkey * val); 
        money = money + total ;  
        cout << "A boom in attendance has occurred! The monkeys have brought in additional revenue of: " <<  total << " You currently have " << money << endl; 
    }
    else{
        cout << "You dont have any monkeys. Therefore no additional revenue was brought in " << endl; 
    }
}
/*******************************************************************
 * ** Function: foodexp
 * ** Description:  Calculates the feeding cost for each animal   
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: returns an updated printed value 
 * *******************************************************************/
void zoo::foodexp(){
   int mcost = 0;
    int scost = 0;
    int secost = 0; 
    int tcost = 0;  
    int ticost = 0; 
   if(day == 1){  //calculating base food cost for day 1 
        if(num_monkey > 0 ){
            mcost = num_monkey * 400; 
        }
        if(num_seaotter > 0 ){ //base cas sea otter expense 
            secost = num_seaotter * 200; 
        }
        if(num_sloth > 0 ){
            scost = num_sloth* 100; 
        }
        if(num_tiger > 0){
            ticost = num_tiger * 100; 
        }
    }
    else{
        srand(time(NULL)); 
        float basecost = (rand() % 50)+ 75;  //randomizing food cost based on each percentage 
        float newnum = (basecost / 100);
        float fcost = (100*newnum);
        if(num_monkey > 0){ //monkey food expense 
            mcost = ((4*fcost) * num_monkey); 
        } 
        if(num_sloth > 0){ //sloth food expense
            scost = fcost * num_sloth;
        }
        if(num_seaotter > 0){ //seaotter expense
            secost = ((2*fcost) * num_seaotter);
        }  
        if(num_tiger > 0){ //tiger expense 
            ticost = ((3*fcost) * num_tiger); 
        } 
    }  
    tcost = mcost + scost + secost +ticost;  //calculation of expense 
    money = (money - tcost); 
    cout << "-----------------------------------" << endl;  //printing on screen money in bank 
    cout << "The total food cost is: " <<tcost << endl; 
    cout << "Money: " << money << endl; 
     if(money <= 0){
       set_bankrupt(true); 
   }
}
/*******************************************************************
 * ** Function: ~zoo
 * ** Description:  The destructor  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: deletes allocated memory 
 * *******************************************************************/
zoo::~zoo(){
        delete [] monkey; 
        delete [] sloths;
        delete [] seaotters; 
} 
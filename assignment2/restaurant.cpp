#include "restaurant.h"
#include "menu.h"
#include "emp_hours.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;
/*******************************************************************
 * ** Function: Restaurant()
 * ** Description: default constructor  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Restaurant::Restaurant(){ //default constructor 
    //Menu menu; //kinda confused with this line
    num_employees = 0; 
    num_days = 0;
    employees = NULL; //sets pointer to zero 
    week = NULL; 
    orders = NULL;
    num_orders = 0;
    phone = "empty"; 
    address = "empty"; 
    name = "empty"; 
}
//non-default constructor
/*******************************************************************
 * ** Function: Restaurant( string name1, string phone1,string address1,int num_e, int num_d)
 * ** Description: non-default constructor  
 * ** Parameters: string name1, string phone1,string address1,int num_e, int num_d
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Restaurant:: Restaurant( string name1, string phone1,string address1,int num_e, int num_d){
    name = name1; 
    phone = phone1; 
    address = address1; 
    num_employees = num_e;
    num_days = num_d; 
    //num_orders = ordn; 
    employees = new employee[num_employees];
    week = new hours[num_days]; 
    orders = new order[num_orders];  

}
//copy constructor 
/*******************************************************************
 * ** Function: Restaurant(const Restaurant& r1)
 * ** Description: copy constructor  
 * ** Parameters: const Restaurant& r1
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Restaurant::Restaurant(const Restaurant& r1){
    name = r1.name;
    phone = r1.phone;
    address = r1.address;
   // num_employees = r1.num_employees;
    //num_days = r1.num_days;
   // if(employees == 0){
    //    employees == NULL; 
     //   delete [] employees; 
      //  delete [] week; 
     //}
     //else{
       employees = new employee [num_employees];
       for(int i = 0; i<num_employees; i++){
       employees[i] = r1.employees[i];
       }
     //} 
        week = new hours [num_days];
       for(int i = 0; i<num_days; i++){
         week[i] = r1.week[i];
      }
      orders = new order[num_orders];
      for(int i = 0; i<num_orders; i++){
          orders[i] = r1.orders[i]; 
      } 
    
}
//assignment operator overload 
/*******************************************************************
 * ** Function: Restaurant& Restaurant::operator=(const Restaurant& r1)
 * ** Description: assignment operator overload 
 * ** Parameters:const const Restaurant& r1
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Restaurant& Restaurant::operator=(const Restaurant& r1){
    name = r1.name;
    phone = r1.phone;
    address = r1.address;
    //num_employees = r1.num_employees;
    //num_days = r1.num_days;
   // if(employees != NULL){
     //   delete [] employees; 
      //  delete [] week;
      //  delete [] orders; 
        
    //}
    //if(num_employees == 0){
      //  employees = NULL;
       // week = NULL; 
    //}
    //else{
       employees = new employee [num_employees];
       for(int i = 0; i<num_employees; i++){
          employees[i] = r1.employees[i];
       } 
        week = new hours[num_days];
       for(int i = 0; i<num_days; i++){
          week[i] = r1.week[i];
       }
       orders = new order[num_orders];
      for(int i = 0; i<num_orders; i++){
          orders[i] = r1.orders[i]; 
      } 
    //} 
    return *this; 


}
/*******************************************************************
 * ** Function: get_name(), get_num_employee(),get_num_order(),get_phone()
 * ** Description: Accessors function 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: constant
 * *******************************************************************/
int Restaurant::get_num_employees()const{
    return num_employees;
}
int Restaurant::get_num_days()const{
    return num_days;
}
int Restaurant::get_num_orders()const{
    return num_orders; 
}
/* int Restaurant::get_num_porders()const{
    return numpizzao; 
} */
string Restaurant::get_name() const{
    return name; 
}
employee* Restaurant::get_employee(int i)const{
    return &employees[i]; 
}
string Restaurant::get_phone() const{
    return phone; 
}
string Restaurant::get_address() const{
    return address; 
}
/*******************************************************************
 * ** Function: set_name(),set_phone(), set_employeearr, set_weekarr
 * ** Description: mutator functions 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::set_name(string n){
    name = n;
}
void Restaurant::set_phone(string ph){
    phone = ph;
}
void Restaurant::set_employeesarr(employee* emp){
   employees = emp;
}
void Restaurant::set_address(string addy){
    address = addy;
}
void Restaurant::set_weekarr(hours* weeks){
   week = weeks;
}
/*******************************************************************
 * ** Function: view_hours 
 * ** Description: views the hours from the restaruant text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::view_hours(){
    cout << "The hours are listed below: "<< endl; 
    for(int i = 0; i< get_num_days(); i++){
       cout <<  week[i].day << " " << week[i].open_hour << "am" << " " << week[i].close_hour << "pm"<<  endl; 
    }
}
/*******************************************************************
 * ** Function: set_orders 
 * ** Description: reads in the respected informaitn from orderes text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
 void Restaurant::set_orders(){
   ifstream orderinput; 
    orderinput.open("orders.txt", ifstream :: in);
      orderinput >> num_orders; 
       //cout << num_orders << endl; 
        orders = new order[num_orders];
      for(int i = 0; i< get_num_orders(); i++){
         orderinput >>  orders[i].ordernum >>  orders[i].cname  >> orders[i].creditcard >> orders[i].cphone >> orders[i].pizzaname >> 
         orders[i].size>> orders[i].quantity >> orders[i].pizzaname2 >> orders[i].size2 >> orders[i].quantity2;  
        }
   orderinput.close(); 
}  
/*******************************************************************
 * ** Function: view_order 
 * ** Description: views the orders from orders.txt 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::view_orders(){
    cout << "The current number of orders and each order: " << endl; 
    ifstream orderead;  
    string word;
    orderead.open("orders.txt"); 
        while(getline(orderead,word)){
            cout << word << endl;
        }    
    orderead.close();
//once open read the entire file 
}
/*******************************************************************
 * ** Function: remove_order
 * ** Description: removes an order from the order text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::remove_orders(){
    ifstream orderinput;
    ofstream newinput; 
    string replace;
    orderinput.open("orders.txt"); 
    newinput.open("new.txt");
    cout << "Please enter the order number of the order you would like to remove: "<< endl; 
    int ordernum;  //user input that decides which file to remove 
    cin>>ordernum; 
    cin.ignore();
    cout << "Please enter the name of the order as well: " << endl; 
    string ordername; //additional info to help determine which file to remove
    getline(cin,ordername); 
    newinput << (get_num_orders() - 1) << endl; 
    for(int i = 0; i< get_num_orders(); i++){
       if(orders[i].cname != ordername){ // informaiton to determine which file to remove 
            newinput << orders[i].ordernum << " ";
            newinput << orders[i].cname << " ";// informaiton necessary to meet the standards of  removing a order 
            newinput << orders[i].creditcard << " ";
            newinput << orders[i].cphone << " ";
            newinput << orders[i].pizzaname<< " ";// informaiton necessary to meet the standards of  removing a order 
            newinput << orders[i].size << " ";
            newinput << orders[i].quantity << " ";
            newinput << orders[i].pizzaname2<< " ";
            newinput << orders[i].size2 << " ";// informaiton necessary to meet the standards of  removing a order 
            newinput << orders[i].quantity2 << " ";
       }
       newinput << endl; 
    }  
    newinput.close();
    orderinput.close();
    remove("orders.txt");
    rename("new.txt","orders.txt"); 
}
/*******************************************************************
 * ** Function: remove_from_menu
 * ** Description: removes a pizza from the menu
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::remove_from_menu(){
    menu.set_menu(); 
    ifstream menuinput;
    ofstream newinput; // creating a new file to write to 
    string replace;
    menuinput.open("menu.txt"); 
    newinput.open("new.txt");
    cout << "Please enter the pizza you would like to remove: "<< endl; 
     string pizzaname;  //informaiton to determine which file to remove 
    cin>>pizzaname; 
    cin.ignore();
    int firstnum = menu.get_num_pizzas();
    newinput << (firstnum - 1)  << endl; 
    for(int i = 0; i< menu.get_num_pizzas(); i++){
       if(menu.get_pizzas(i).get_name() != pizzaname){ //indicates what to remove 
            
            newinput << menu.get_pizzas(i).get_name() << " "; //since it doesnt meet the parameter write this to the new file 
            newinput << menu.get_pizzas(i).get_smallcost()<< " ";
            newinput << menu.get_pizzas(i).get_mediumcost() << " ";
            newinput << menu.get_pizzas(i).get_largecost() << " ";
            newinput << menu.get_pizzas(i).get_num_ingredients() << " ";
            for(int l = 0; l< menu.get_pizzas(i).get_num_ingredients();l++){
                newinput << menu.get_pizzas(i).get_ingredients(l) << " ";
            }
            newinput << endl; 
       }
       //cout << endl; 
      }
        
    newinput.close();
    menuinput.close();

    remove("menu.txt");
    rename("new.txt","menu.txt"); 
    
}
/*******************************************************************
 * ** Function: place_order
 * ** Description: adds an order to the order function 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::place_order(){
    //menu.set_menu();
    view_menu(); 
    set_orders(); 
    ofstream orderinput; 
    orderinput.open("orders.txt", ios::app); //allows you to write to the file 
    string pizname,customername,phonenum; 
    int quantity,cc,size,ordernums,num1;   //gaining necessary informaiton to add an order 
    cout << "Please enter you credit card number(no spaces or dashes please): " << endl; 
    cin >> cc; 
    cin.ignore();  
    cout << "Please enter you name: " << endl; //neccesarry info 
    cin >> customername; 
     cin.ignore(); 
    cout << "Please enter the name of the pizza: "<< endl; //neccesarry info 
    cin >> pizname;  
    cout << "Please enter the size S(1), M(2), L(3):  " << endl; //neccesarry info 
    cin >> size; 
    cin.ignore(); 
    cout << "Please enter your phone number:  " << endl; //neccesarry info 
    cin >> phonenum; 
    cout << "How many " << pizname << " would you like to order: " << endl; 
    cin >> quantity ; 
    cin.ignore(); 
    num1 = get_num_orders(); 
    cout << num1 << endl ; //outputting the informaiton into the text file 
    orderinput << endl; 
    orderinput << (num1 + 1)<< " "; 
    orderinput << customername << " "; 
    orderinput << cc << " "; 
    orderinput << phonenum << " "; 
    orderinput << pizname << " "; 
    for(int i = 0; i< menu.get_num_pizzas(); i++){ //printing the desired size 
        if(menu.get_pizzas(i).get_name() == pizname){
          if(size == 1){
              orderinput << " S " ;  
             // orderinput << menu.get_pizzas(i).get_smallcost() << " ";
          }
          else if(size == 2){
              orderinput << " M " ;  
             // orderinput << menu.get_pizzas(i).get_mediumcost() << " ";
          }
          else{
              orderinput << " L " ;  
              //orderinput << menu.get_pizzas(i).get_largecost() << " ";
          }
        }
        //orderinput << endl; 

    }
    orderinput <<  quantity << " ";  //writing the number of the designated pizza 
    orderinput.close(); 
    
}
/*******************************************************************
 * ** Function: view_menu
 * ** Description: printing the informaiton from the menu text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::view_menu(){
     menu.set_menu(); 
      cout << "The Menu is listed below: " << endl; 
      for(int i = 0; i< menu.get_num_pizzas(); i++){
         cout <<  menu.get_pizzas(i).get_name() << " " << menu.get_pizzas(i).get_smallcost() << " " << menu.get_pizzas(i).get_mediumcost() << " " 
         << menu.get_pizzas(i).get_largecost() << " " <<  menu.get_pizzas(i).get_num_ingredients() << " "; 
         //cout << menu.get_pizzas(i).get_mediumcost() ; 
         for(int l=0;l<menu.get_pizzas(i).get_num_ingredients(); l++){
             cout << menu.get_pizzas(i).get_ingredients(l) << " " ; 
         }
         cout << endl; 
      }
      
}
/*******************************************************************
 * ** Function: view_address
 * ** Description: view phone info from text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::view_address(){
    //set_restaurant_data(); 
    cout << "The address is: " << endl; 
    cout << get_address() << endl; 

}
/*******************************************************************
 * ** Function: view_phone()
 * ** Description: view phone info from text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::view_phone(){
    cout << "Phone Number:" << " ";
    cout << get_phone() << endl; 

}
/*******************************************************************
 * ** Function: set_employee_data 
 * ** Description: reads informaiton in from the employee text file  
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::set_employee_data(){
   ifstream employeeinput; 
   employeeinput.open("employee.txt", ifstream :: in);
   if(employeeinput.is_open()){
      employeeinput >> num_employees; 
      employees = new employee[num_employees];
      for(int i = 0; i<num_employees; i++){
          employeeinput >>  employees[i].id >>  employees[i].password  >> employees[i].first_name >> employees[i].last_name ;  
      }
   }
   employeeinput.close(); 
}
/*******************************************************************
 * ** Function: set_restaurant data 
 * ** Description: reads informaiton in from the restaurant text file  
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::set_restaurant_data(){
    ifstream restaurantinput; 
    restaurantinput.open("restaurant_info.txt", ifstream :: in);
        getline(restaurantinput,name) ; 
        getline(restaurantinput,phone); 
        getline(restaurantinput,address); 
        restaurantinput >> num_days; 
        week = new hours[num_days];
        for(int i = 0; i<num_days; i++){
          restaurantinput >> week[i].day >>  week[i].open_hour  >> week[i].close_hour;   
         }
      restaurantinput.close();
}
/*******************************************************************
 * ** Function: search_menu_by_price(int cost)
 * ** Description: searches the menu by user specified cost 
 * ** Parameters:the cost max
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::search_menu_by_price(int cost){
    menu.set_menu(); 
    cout << "Small pizzas that fit in your price range: " << "\n";  //searching small cost 
    for(int i = 0; i< menu.get_num_pizzas(); i++){
        if(menu.get_pizzas(i).get_smallcost() <= cost){//indicates value has to be less than or equal to user inputed value 
            cout<< menu.get_pizzas(i).get_name() << " " ;
            cout<< menu.get_pizzas(i).get_smallcost() << " " ; 
            for(int l = 0; l< menu.get_pizzas(i).get_num_ingredients(); l++){
                cout<< menu.get_pizzas(i).get_ingredients(l) << " "  ; 
            }
        }
      cout << endl; 
    }

    cout << "Medium pizzas that fit in your price range: " << "\n";  //searching for medium cost  
    for(int i = 0; i< menu.get_num_pizzas(); i++){
        if(menu.get_pizzas(i).get_mediumcost() <= cost){ //indicates value has to be less than or equal to user inputed value 
            cout<< menu.get_pizzas(i).get_name() << " " ;
            cout<< menu.get_pizzas(i).get_mediumcost() << " " ; 
            for(int l = 0; l< menu.get_pizzas(i).get_num_ingredients(); l++){
                cout<<  menu.get_pizzas(i).get_ingredients(l) << " "  ; 
            }
        }
       cout << endl; 
    }
    cout << "Large pizzas that fit in your price range: " << "\n"; //searching for large cost 
    for(int i = 0; i< menu.get_num_pizzas(); i++){
        if(menu.get_pizzas(i).get_largecost() <= cost){ //indicates value has to be less than or equal to user inputed value 
            cout<< menu.get_pizzas(i).get_name() << " " ;
            cout<< menu.get_pizzas(i).get_largecost() << " " ; 
            for(int l = 0; l< menu.get_pizzas(i).get_num_ingredients(); l++){
                cout<< menu.get_pizzas(i).get_ingredients(l) << " "  ; 
            }
        }
      cout << endl; 
    }
    cout << "Would you like to place and order? Yes-1 and No-2 " << endl; 
    cin.ignore(); 
    int choice; 
    cin>> choice; 
    if(choice == 1){
     place_order();    
    }

    
}
/*******************************************************************
 * ** Function: search_by_ingredients(string ingr)
 * ** Description: Searching the menu by user specified ingredients 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::search_by_ingredients(string ingr){
    menu.set_menu();
    for(int i = 0; i< menu.get_num_pizzas(); i++){
       // cout << "one1 " << endl;
        for(int p = 0; p < menu.get_pizzas(i).get_num_ingredients(); p++){
            if(menu.get_pizzas(i).get_ingredients(p) == ingr){ //idenitifiying if the ingredient is included 
                cout << menu.get_pizzas(i).get_name() << " "; 
                cout << menu.get_pizzas(i).get_smallcost() << " "; 
                cout << menu.get_pizzas(i).get_mediumcost() << " "; 
                cout << menu.get_pizzas(i).get_largecost() << " ";
                for(int l = 0; l< menu.get_pizzas(i).get_num_ingredients(); l++){ //ingredients is an array therefore you nee to loop to access each element
                cout << menu.get_pizzas(i).get_ingredients(l) << " ";  
                }
                cout << endl;
            }
            
        }
    }
}
/*******************************************************************
 * ** Function:search_by_eingredients(string ingr)
 * ** Description:  search by excluding ingredients specified by the user  
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::search_by_eingredients(string ingr){
    menu.set_menu();
    for(int i = 0; i< menu.get_num_pizzas(); i++){
            if(menu.get_pizzas(i).get_ingredients(i) != ingr){
                for(int p = i; p<menu.get_num_pizzas(); p++){
                  cout << menu.get_pizzas(i).get_name() << " "; 
                  cout << menu.get_pizzas(i).get_smallcost() << " "; 
                  cout << menu.get_pizzas(i).get_mediumcost() << " "; 
                  cout << menu.get_pizzas(i).get_largecost() << " ";
                  for(int l = 0; l< menu.get_pizzas(i).get_num_ingredients(); l++){
                    cout << menu.get_pizzas(i).get_ingredients(l) << " ";  
                  }
                   cout << endl;
                }
            }
            
    }
}
/*******************************************************************
 * ** Function: add_to_menu
 * ** Description: Adds a pizza to the menu 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::add_to_menu(){
    ofstream menuappend; 
    ifstream newinput ; 
    menuappend.open("menu.txt", ios::app);
    menuappend << "\n"; //below is the information necessary to create a new order 
    cout << "Please enter the new menu item: " << endl; 
    string newpizza; 
    cin >> newpizza; 
    cout << "Please enter the cost for a small pizza: " << endl; 
    int smallprice,mediumprice,largeprice; 
    cin >> smallprice; 
    cout << "Please enter the cost for a medium pizza: " << endl; 
    cin >>mediumprice;
    cout << "Please enter the cost for a large pizza: " << endl; 
    cin >> largeprice;
    cout<< "Please enter the number of ingredients: " << endl; 
    int ingrenum; 
    cin >> ingrenum; 
    cin.ignore();
    string ingredi; 
    menuappend << newpizza << " " ; //adding the new items specifications to the text file 
    menuappend << smallprice << " ";
    menuappend << mediumprice << " " ; 
    menuappend << largeprice << " " ;
    menuappend << ingrenum << " ";
     for(int i = 0; i<ingrenum ; i++){
        cout << "please list your ingredients individually: " << endl; 
        getline(cin,ingredi);
        menuappend << ingredi << " "; 
        //cin.ignore();
    }
    menuappend << "\n";
    menuappend.close();

}
/*******************************************************************
 * ** Function: change_hours()
 * ** Description: Changes the restaruants hours in the restaurant text file 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Restaurant::change_hours(){ // need help with this function
    //set_restaurant_data();
    //cout << get_num_days() << endl;
    int num; 
    int opentime1,opentime2,opentime3,opentime4,opentime5,opentime6, opentime7;
    int closetime1,closetime2,closetime3,closetime4,closetime5,closetime6,closetime7; 
    cout<< "Please adjust the hours as you would like:" << endl ; // all code below is necessary because you need to update the hours of each day 
    do{
       cout<< "New hours for Monday: " << "\n" << "Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime1; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime1; 
       cin.ignore();
       num = 1; 
       cout<< "New hours for Tuesday: " << "\n" <<"Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime2; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime2; 
       cin.ignore();
       num = 2;
       cout<< "New hours for Wednesday: " << "\n""Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime3; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime3; 
       cin.ignore();
       num = 3;
       cout<< "New hours for Thursday: " << "\n" <<"Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime4; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime4; 
       cin.ignore();
       num = 4;
       cout<< "New hours for Friday: " << "\n" << "Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime5; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime5; 
       cin.ignore();
       num = 5;
       cout<< "New hours for Saturday : " << endl; 
       cout<< "Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime6; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime6; 
       cin.ignore();
       num = 6;
       cout<< "New hours for Sunday: " << endl; 
       cout<< "Please enter the time you would like to open: (please enter numbers only)" << endl; 
       cin>> opentime7; 
       cin.ignore();
       cout<< "Please enter the time you would like to close: (please enter a number only) " << endl; 
       cin>> closetime7; 
       cin.ignore();
       num = 7;
    } 
    while( num != get_num_days());
    ofstream outputinput; 
    string outputfile;  
    outputinput.open("restaurant_info.txt"); //opening the text file to insert  new hours 
        outputinput << get_name() << endl ; 
        outputinput << get_phone() << endl;
        outputinput << get_address() << endl;
        outputinput << get_num_days() << endl;
        outputinput << "Monday" << " " << opentime1 << " "  << closetime1 << endl;  //updating the text file to the new hours 
        outputinput << "Tuesday" << " " << opentime2 << " "  << closetime2 << endl; 
        outputinput << "Wednesday" << " " << opentime3 << " "  << closetime3 << endl; 
        outputinput << "Thursday" << " " << opentime4 << " "  << closetime4 << endl; 
        outputinput << "Friday" << " " << opentime5 << " "  << closetime5 << endl; 
        outputinput << "Saturday" << " " << opentime6 << " "  << closetime6 << endl; 
        outputinput << "Sunday" << " " << opentime7 << " "  << closetime7 << endl; 
  outputinput.close(); 
}
/*******************************************************************
 * ** Function: login()
 * ** Description: Tests employee login 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
bool Restaurant::login(){
  bool test; 
  string username,password;  // gaining user login credentials below
    cout << "Please Enter your username: " << endl; 
    cin >> username; 
    cin.ignore();
    cout <<"Please enter you password " << endl; 
    getline(cin,password);
    //cin.ignore(); 
    for(int i = 0; i < num_employees; i++){ //comparison to see if username and password matches that of the text file
        if(atoi(username.c_str())== employees[i].id  &&  password == employees[i].password ){
             cout << employees[i].first_name << " " << employees[i].last_name << endl;
            return true; 
        }
    }
    return false; 
}
/*******************************************************************
 * ** Function: ~Restaurant
 * ** Description: destructor deletes the arrays allocated in the class 
 * ** Parameters:none
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
//destructor 
Restaurant::~Restaurant(){
    delete [] employees;
    delete [] week;
    delete [] orders; 
    //cout << "Restaurant destructor call" << endl; 
}
#include <iostream> 
#include <stdlib.h>
#include "./multdiv.h"
using namespace std; 


int main(int argc, char** argv){
    cout<< "rows: " << argv[1] << " cols: " << argv[2] << endl; 
    int row = atoi(argv[1]); 
    int col = atoi(argv[2]);
    if (argc != 3){ // error handling for to many or to few command lines 
      cout <<"To many command line arguments entered. Please compile the program again and only enter three command line arguments" << endl; 
     return 0; 
    } 
    int testval; 
    testval = is_valid_dimensions(argv[1],argv[2]);
    if(testval = 1){
       int answer; 
       do{
       multdiv_entry **table2 = create_table(row,col);
       print_table(table2,row,col);
       delete_table(table2,row);
       cout << "would you like to see a different matrix? (0-yes,1-no)" << endl; 
       cin >> answer; 
       if (answer == 0){
       cout <<"the number of rows: " << endl; 
       cin >> row; 
       cout <<"the number of columns " << endl; 
       cin >> col; 
       cin.ignore();
     }
     }
     while(answer == 0);
     }
     else {
      cout<< "Please enter a valid integer of rows: " << endl; 
      cin >> row; 
      cout<< "Please enter a valid integer of columns: " << endl; 
      cin >> col;
     }
    
}
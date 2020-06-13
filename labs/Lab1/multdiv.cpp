#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include "./multdiv.h"
using namespace std; 

bool is_valid_dimensions(char* m, char* n){

    if(m <= 0){
      cout << "invalid number of rows:  " << endl; 
      return false; 
    }
    else if(n<= 0){
      cout << "invalid number of columns:  " << endl; 
      return false;  
    }
    else {
    return true; 
    }
}
multdiv_entry** create_table(int row, int col){
   multdiv_entry **table = new multdiv_entry*[row];
   for(int i = 0; i< row; i++){
      table[i] = new multdiv_entry[col]; 
   }
   return table; 
}
void print_table( multdiv_entry** table, int row, int col){
  cout << " Multiplication Table:" << endl; 
   for(int l = 0; l<row; l++){
     for(int p = 0; p<col; p++){
       table[l][p].mult = (l+1)*(p+1);
       cout << table[l][p].mult << "\t";
     }
     cout << endl;
   }
   cout<< endl;
   cout<<"  Division Table: "<< endl; 
   for(int i = 0; i<row;i++){
     for(int k = 0; k<col;k++){
       table[i][k].div = (double)(i+1)/(double)(k+1);
       cout << setprecision(2) << table[i][k].div << "\t" ;
     }
     cout << endl;
   }
   cout << endl;
}
void delete_table(multdiv_entry** table, int row){
   for(int i = 0; i<row;i++){
     delete [] table[i];
   }
 delete [] table; 
}

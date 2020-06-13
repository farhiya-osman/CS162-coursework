#include "lab9.h"


int main(){
    lab9 l; 
  cout << " Please enter the desired length of the array. " << endl; 
  int option; 
  cin >> option;  
   int* arr = new int[option]; 
  if (option >=0 && option <=20 ){
      l.populate_arr(option, arr); 
      l.msort2(arr,0, option-1); 
      for(int i = 0; i<option; i++){
          cout << "Sorted array: " << arr[i] << " "; 
      }
      cout << endl; 
      l.primenumber(arr,option); 
      // perform merge sort 
  }
  else{
      cout<< "Invalid size entry please enter a length between 0 and 20 " << endl; 
      cin >> option; 
  }
}

#ifndef LAB9_H
#define LAB9_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string> 

using namespace std; 

class lab9 {
  private:

public:
  void populate_arr(int size, int *arr){
      srand(time(NULL)); 
     for(int i = 0; i<size; i++){
         int randval = ((rand()%49)+1); 
         arr[i] = randval; 
         cout << "Elements in the array: " << arr[i] << endl; 
     }
   }
   void msort(int *arr,int l, int m, int r){
       int i,j,k; 
       int n1 = m-l+1;
       int n2 = r-m; 

       int *L = new int[n1]; 
        int *R = new int [n2]; 

       for(i = 0;i<n1;i++){
            L[i] = arr[l+i]; 
       }
        for(j=0;j<n2;j++){
           R[j] = arr[m+1+j]; 
       } 
       j=0;
       k=l; 
       while(i<n1 && j < n2)
       {
           if(L[i] <= R[j])
           {
               arr[k] = L[i];
               i++;
           }
           else
           {
               arr[k] = R[j]; 
               j++;
           }
           k++;   
       }

       while(i<n1)
       {
           arr[k] = L[i]; 
           i++; 
           k++;
       }
       while(j<n2)
       {
           arr[k] = R[j]; 
           j++;
           k++;
       }
       
   }
   void msort2(int *arr, int l, int r){
    int val;
    if(l<r){
        val  =  l+(r-l)/2; 
        msort2(arr,l,val); 
        msort2(arr,val+1,r); 
        msort(arr,l,val,r); 
    }
   }
   void primenumber(int *arr, int option){
       int count = 0; 
   //cout << "Prime numbers in the array: " ; 
       for(int i = 0;  i< option; i++){
           if(arr[i]%2 !=0){
              if(arr[i]%3 !=0){   
                if(arr[i]%5 !=0){
                  if(arr[i]%7 !=0){
                      count++;
                       //cout << arr[i] << " ,"; 
                  }
              }
           }
       }
   }
        cout << endl; 
         cout << "The number of prime numbers in the array are: " << count << endl;   
}
};

#endif
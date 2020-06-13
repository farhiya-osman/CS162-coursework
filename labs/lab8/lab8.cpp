#include "./lab8.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
  v.resize(6,8); 
   
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
   v[5]; 
   try
   {
      v.at(6); 
   }
   catch(const std::out_of_range & e)
   {
      std::cerr << e.what() << '\n';
   }
   
   

  /*  for(int i = 0 ; i< 7 ;i++){
       cout << "Value of var[ " << i << " ] = " << v[i] << endl; 
   } */
   //v.at(450); 


   return 0;
}
#include <stdlib.h>
#include <stdexcept>
#include <vector>
template <class T>
class vector {
   private:
      T *v;
      int s;
      int capacity; 
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	   vector(vector &other){
         v = new T[other.s];
         s = other.s; 
         for(int i =0; i<s;i++){
            v[i] = other.v[i]; 
         }
      } 
      T operator[](int a){
        return v[a]; 
      }
      T at(int b){
       if(b >= s || b < 0 ){
          throw std::out_of_range("Out of bounds"); 
       }
       return v[b];  
      }
      void operator=(vector<T> &other){ 
         v = new T[other.s];
         s = other.s; 
         for(int i =0; i<s;i++){
            v[i] = other.v[i]; 
         }
      }
      ~vector(){
	     delete [] v;
      }
	  
      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
      if(s >= capacity){
         //s = (2*s); 
         capacity = 2*capacity; 
         T *temps;
	     temps = new T[capacity];
	     for(int i=0; i<s; i++)
	        temps[i]=v[i];

	     delete [] v;
	     v=temps;
	     v[s]=ele;
        s++;
      }
      else if(s<capacity){
         s++;
         v[s-1] = ele ; 

     /*      T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;  */
      }    
      }
      void resize(int n, const int& val ){
        T * arr; 
        arr = new T[++n];
        for(int i=0; i<n-1; i++)
	        arr[i]=v[i];

	     delete [] v;
	     v=arr;

      }
	    
      
      
};
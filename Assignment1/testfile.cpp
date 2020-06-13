#include <iostream> 
#include <fstream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std; 
void printfunction();

void writetofile(){
 
  ofstream outputinput; 
  string outputfile; 
   cout << "Please enter the file you would like to write into: " << endl; 
   cin >> outputfile; 
  int outputsize; 
  
   outputinput.open(outputfile.c_str(), ios::app);

  /* if(outputinput.fail()) {
        cout << "This file does not exist. creating  a new file"  << endl; 
        string newfile; 
        cin >> newfile; 
        ofstream file; 
        file.open(newfile.c_str()); 
        file << " hello ";
    }
  */ 
  if(outputinput.is_open()){
        outputinput << "five nine " << endl;  
    }

  outputinput.close();
}

void printfunction(){
    cout << "Hello one two three " << endl; 
}

int main(){

 writetofile();

}
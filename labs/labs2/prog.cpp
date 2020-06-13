#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "lab2.h"

using namespace std; 

int main(){
    ifstream inputfile;  
    string filename; 
    int studentsnum;
   
    cout<< "Please enter a file name" << endl; 
    cin>>filename;
    inputfile.open(filename.c_str());
    while(inputfile.fail()){
        cout << "This file does not exist. Pleas enter a valid file name: " << endl; 
        cin>>filename; 
        inputfile.open(filename.c_str());
    }
    if(inputfile.is_open()){
        inputfile>>studentsnum; 
        student * students2 = create_student_db(studentsnum);
        populate_student_db_info(students2,studentsnum,inputfile); 
        sortID(students2,studentsnum); 
        sortlastname(students2,studentsnum);
        printorder (students2,studentsnum); 
        sortmajor(students2,studentsnum);
        cout << "The results will be printed in this output.txt " << endl; 
         ofstream file("output.txt"); 
        file << "unique majors: " << sortmajor(students2,studentsnum) << endl;
        file << "Sorted ID numbers " << endl; 
    for (int i = 0; i< studentsnum; i++){
        file << students2[i].Idnum << endl; 
    }
      file << endl; 
      file << "Sorted Last names: " << endl; 
    for (int i = 0 ; i <studentsnum; i++){
        file << students2[i].lastname << endl; 
    }
    inputfile.close();
    delete_student_db_info(&students2,studentsnum);
    }
}
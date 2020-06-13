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

student * create_student_db(int studentsnum){
    student * students = new student[studentsnum];

return students; 
}
void populate_student_db_info(student* students , int studentsnum, ifstream& inputfile ){
    for(int l = 0; l<studentsnum; l++){
        inputfile >> students[l].Idnum; 
        inputfile >> students[l].lastname;
        inputfile >> students[l].firstname;
        inputfile >> students[l].major;

    }
}
void sortID(student * students, int studentsnum){
    student smallest; 
    for(int i = 0; i<studentsnum; ++i){
    for(int p = 0; p<studentsnum- 1; ++p){
        if(students[p].Idnum > students[p+1].Idnum){
            smallest.Idnum = students[p].Idnum; 
            students[p].Idnum = students[p+1].Idnum; 
            students[p+1].Idnum = smallest.Idnum;
            
        }
      } 
    }
}
void sortlastname(student * students, int studentsnum){
    student nameorder; 
    for(int i = 1; i<studentsnum; i++){
    for(int p = 0; p<studentsnum - 1; p++){
        if(students[p].lastname > students[p+1].lastname){
            nameorder.lastname = students[p].lastname; 
            students[p].lastname = students[p+1].lastname; 
            students[p+1].lastname= nameorder.lastname;   
        }
      } 
   }
    
}

void printorder (student * students, int studentsnum){
    cout << "The sorted Id: " << endl; 
    for(int i = 0; i<studentsnum; i++){
        cout << students[i].Idnum <<"\t" << endl; 
    }
    cout << "The Sorted last names are: " << endl; 
    for(int k = 0; k<studentsnum; k++){
        cout << students[k].lastname << "\t"; 
        cout << endl; 

    }

}
int sortmajor(student * students, int studentsnum){
    int unique = 0;  
    for(int i = 0; i<studentsnum -1; i++){
        if(students[i].major != students[i+1].major){
            unique++;
        } 
    } 
   cout << "The number of unique majors are: " << unique << endl;     
}

void delete_student_db_info(student** students, int studentsnum){
        delete [] (*students); 
        (*students) = NULL;

}
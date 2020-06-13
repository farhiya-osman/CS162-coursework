#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std; 

struct student{
    int Idnum; 
    string lastname;
    string firstname; 
    string major; 
};
void sortID(student * students, int studentsnum);
void populate_student_db_info(student* students , int studentsnum, ifstream& inputfile );
student*create_student_db(int studentsnum);
void sortlastname(student * students, int studentsnum);
int sortmajor(student * students, int studentsnum);
void delete_student_db_info(student** students, int studentsnum);
void printorder (student * students, int studentsnum);
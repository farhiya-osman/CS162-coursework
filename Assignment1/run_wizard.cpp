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

struct spellbook {
       string title;
       string author;
       int num_pages;
       int edition;
       int num_spells;
       float avg_success_rate;
       struct spell *s;
};
 struct spell {
       string name;
       float success_rate;
       string effect;
};
struct wizard {
       string name;
       int id;
       string password;
       string position_title;
       float beard_length;
};
spellbook * create_spellbooks(int);
void logininfo(wizard* wizard1 , int wizardsize);
wizard * create_Wizard(int wizardsize);
void populate_wizard_data(wizard * wizard1, int wizardsize, ifstream& wizardinput);
void sortbypage(spellbook * spellb, int spellbooksize);
void sortingoption(spellbook * spellb, int spellbooksize);
void sortbysuccess(spellbook * spellb, int spellbooksize);
void populate_spellbook_data(spellbook * spellb, int spellbooksize, ifstream& spellbookinput);
void printfunction(spellbook * spellb, int spellbooksize);
void booksuccesrate(spellbook *spellb);
int sortbyeffect(spellbook * spellb, int spellbooksize);
void writetofile(spellbook * spellb, int spellbooksize);
void delete_info2( spellbook ** spellb,  int spellbooksize);
void delete_info(wizard** wizard1,int wizardsize);
void studentsortbypage(spellbook * spellb, int spellbooksize);


int main(int argc, char** argv){
  ifstream wizardinput; 
  string wizardfile; 
  wizardfile = argv[1];
  int wizardsize; 

  ifstream spellbookinput; 
  string spellbookfile; 
  spellbookfile = argv[2];
  int spellbooksize; 

  spellbookinput.open(spellbookfile.c_str());
  wizardinput.open(wizardfile.c_str());
  while(spellbookinput.fail() || wizardinput.fail()){
        cout << "This file does not exist."  << endl; 
        return 0 ; 
    }
 
 
 if(wizardinput.is_open()){
    wizardinput >> wizardsize; 
     wizard* wizard2 = create_Wizard(wizardsize); 
     populate_wizard_data(wizard2,wizardsize,wizardinput);
     logininfo(wizard2,wizardsize);
     delete_info(&wizard2,wizardsize);
     wizardinput.close();
  }
  if(spellbookinput.is_open()){
    spellbookinput >> spellbooksize; 
    spellbook* spellbook2 = create_spellbooks(spellbooksize); 
    populate_spellbook_data(spellbook2,spellbooksize,spellbookinput);
    sortingoption(spellbook2,spellbooksize);
    delete_info2(&spellbook2,spellbooksize); 
    spellbookinput.close();
  }
}
spell * create_spell(int numspells){
  spell * spell1 = new spell[numspells];
  
  return spell1; 

}
void populate_spell_data(spell * spell1, int numspells, ifstream& spellbookinput){
  for(int i = 0; i< numspells; i++){
  spellbookinput >> spell1[i].name; 
  spellbookinput >> spell1[i].success_rate; 
  spellbookinput >> spell1[i].effect; 
}
}

spellbook * create_spellbooks(int spellbooksize){
    spellbook* spellb = new spellbook[spellbooksize];

return spellb;

}
void sortingoption(spellbook * spellb, int spellbooksize){
  int sortoption ; 
  int displayoption;
  int testval; 
   do{
 
    cout << "Which option would you like to choose? " << endl; 
    cout << "1. Sort spellbooks by number of pages: " <<endl; 
    cout << "2. Group spells by thier effect: " << endl; 
    cout << "3. Sort spellbooks by average success rate: " << endl; 
    cout << "4. quit " << endl; 
    cin >> sortoption; 
      if(sortoption == 4){
        exit(4);
      }
    cout << "Your choice:  " << sortoption << endl; 
    cout << "How would you like your information displayed?" << endl; 
    cout << "1. Print to screen " << endl; 
    cout << "2. Print to file: " << endl; 
    cin >> displayoption;
    cout << "Your choice : " << displayoption << endl; 
      if(sortoption == 1 && displayoption == 1){
        //sortbypagestudents(spellb,spellbooksize);
       // sortbypage(spellb,spellbooksize);
        studentsortbypage(spellb,spellbooksize);
      }
      else if(sortoption == 3 && displayoption == 1){
        booksuccesrate(spellb);
        sortbysuccess(spellb,spellbooksize);
        printfunction(spellb,spellbooksize);
      }
      else if(sortoption == 2 && displayoption == 1){
        sortbyeffect(spellb,spellbooksize);  
      }
      else if(sortoption == 1 && displayoption == 2){
        sortbypage(spellb,spellbooksize);
      }
    }while(sortoption !=4);

}
void populate_spellbook_data(spellbook * spellb, int spellbooksize, ifstream& spellbookinput){
   for(int i = 0; i<spellbooksize; i++){
       spellbookinput >>  spellb[i].title;
       spellbookinput >> spellb[i].author;
       spellbookinput >> spellb[i].num_pages;
       spellbookinput >> spellb[i].edition;
       spellbookinput >> spellb[i].num_spells;
       spellb[i].s = create_spell(spellb[i].num_spells);
       populate_spell_data(spellb[i].s,spellb[i].num_spells,spellbookinput);
       booksuccesrate(&spellb[i]);
   }
}
void booksuccesrate(spellbook *spellb){
   float successrate;
    for(int p = 0; p<spellb->num_spells ; p++){
      successrate += spellb->s[p].success_rate;
      spellb->avg_success_rate = successrate; 
   }
    spellb->avg_success_rate = (spellb->avg_success_rate/spellb->num_spells);
     //cout << spellb->avg_success_rate << endl; 
   
}
void printfunction(spellbook * spellb, int spellbooksize){
  //for(int i = 0; i < spellbooksize; i++){
    //cout << spellb[i].title << " " << "the average success rate: " << spellb[i].avg_success_rate << endl;
    //cout << spellb[i].author << " " << spellb[i].edition <<  endl;
    //for(int p=0; p<spellb[i].num_spells; p++){
     // cout << spellb[i].s[p].name << " " << spellb[i].s[p].success_rate << " " << spellb[i].s[p].effect << endl; 
    //}
 // }
}
void sortbypage(spellbook * spellb, int spellbooksize){
  spellbook smallest; 
       for(int i = 0; i<spellbooksize; i++){
       for(int p = 0; p<spellbooksize; p++){
          if(spellb[p].num_pages > spellb[p+1].num_pages){
            smallest.num_pages = spellb[p].num_pages; 
            spellb[p].num_pages = spellb[p+1].num_pages; 
            spellb[p+1].num_pages = smallest.num_pages;
            smallest.title = spellb[p].title;
            spellb[p].title = spellb[p+1].title; 
            spellb[p+1].title = smallest.title;
        }
       }    
       }
       for (int i = 0; i<spellbooksize; i++){
              cout << spellb[i].title << " " << spellb[i].num_pages << endl; 
       }
}
void studentsortbypage(spellbook * spellb, int spellbooksize){
  spellbook smallest; 
   for(int i = 0; i < spellbooksize; i++){
     for(int p=0; p<spellb[i].num_spells; p++){
        if(spellb[i].s[p].effect != "death"){ 
         if(spellb[i].s[p].effect != "poison"){ 
           cout << spellb[i].title << endl; 
           /*  if(spellb[i].num_pages > spellb[i+1].num_pages){
            smallest.num_pages = spellb[i].num_pages; 
            spellb[i].num_pages = spellb[i+1].num_pages; 
            spellb[i+1].num_pages = smallest.num_pages;
            smallest.title = spellb[i].title;
            spellb[i].title = spellb[i+1].title; 
            spellb[i+1].title = smallest.title;
        }
        */ 
         }
        }
        
    }
   }
      for (int i = 0; i<spellbooksize; i++){
              cout << spellb[i].title << endl;
              //" " << spellb[i].num_pages << endl; 
       }
}
void writetofile(spellbook * spellb, int spellbooksize){
   ofstream outputinput; 
  string outputfile; 
   cout << "Please enter the file you would like to write into: " << endl; 
   cin >> outputfile; 
  int outputsize; 
   outputinput.open(outputfile.c_str(), ios::app);
  if(outputinput.is_open()){
        outputinput << "One two three four" << endl;  
    }
  outputinput.close();
    
}
void sortbysuccess(spellbook * spellb, int spellbooksize){
   spellbook smallest; 
       for(int i = 1; i<spellbooksize; i++){
       for(int p = 0; p < spellbooksize - i; p++){
          if(spellb[p].avg_success_rate > spellb[p+1].avg_success_rate){
            smallest.avg_success_rate = spellb[p].avg_success_rate; 
            spellb[p].avg_success_rate = spellb[p+1].avg_success_rate; 
            spellb[p+1].avg_success_rate = smallest.avg_success_rate; 
             smallest.title = spellb[p].title;
             spellb[p].title = spellb[p+1].title; 
             spellb[p+1].title = smallest.title;
        }     
}
}
    for(int i = 0; i < spellbooksize; i++){
      cout << spellb[i].title << " " << spellb[i].avg_success_rate << endl;
    }
}     
int sortbyeffect(spellbook * spellb, int spellbooksize){
  spellbook smallest ; 
  spell small; 
  // spells need to be ordered by memory loss, fire, posion, death
  for(int i = 0; i<spellbooksize; i++){
  for(int p=0; p<spellb[i].num_spells; p++){
    //int i = int(spellb[i].s[p].effect[0]); 
    if(spellb[i].s[p].effect == "memory_loss"){
      cout << " " << spellb[i].title << " " << spellb[i].s[p].effect << endl; 
    }
  }
  }
  for(int i = 0; i<spellbooksize; i++){
  for(int p=0; p<spellb[i].num_spells; p++){
     if(spellb[i].s[p].effect == "fire"){
      cout << " " << spellb[i].title << " " << spellb[i].s[p].effect << endl; 
     }
  }
  }
  for(int i = 0; i<spellbooksize; i++){
  for(int p=0; p<spellb[i].num_spells; p++){
     if(spellb[i].s[p].effect == "poison"){
      cout << " " << spellb[i].title << " " << spellb[i].s[p].effect << endl; 
     }
  }
  }
  for(int i = 0; i<spellbooksize; i++){
  for(int p=0; p<spellb[i].num_spells; p++){
     if(spellb[i].s[p].effect == "death"){
      cout << " " << spellb[i].title << " " << spellb[i].s[p].effect << endl; 
     }
  }
  } 
} 
wizard * create_Wizard(int wizardsize){
  wizard* wizard1 = new wizard[wizardsize];

return wizard1;
}
void populate_wizard_data(wizard * wizard1, int wizardsize, ifstream& wizardinput){
   for(int i = 0; i< wizardsize; i++){
     wizardinput >> wizard1[i].name;
     wizardinput >> wizard1[i].id;
     wizardinput >> wizard1[i].password;
     wizardinput >> wizard1[i].position_title;
     wizardinput >> wizard1[i].beard_length;
   }
}
void logininfo(wizard* wizard1 , int wizardsize){ 
   int testval = 0; 
  int counter = 0 ; 
  do{
    cout<< "Please enter your ID: " << endl;
    string username; 
    cin >> username; 
    for(int i = 0; i< username.length(); i++){
      if(username[i] < 48 || username[i] > 57){
       cout<< "Error the ID must be all integers. Please enter another ID: " << endl;
       cin.clear(); 
       cin.ignore();
       cin >> username; 
       }
    }
    cout << "Please enter a password: " << endl; 
    string password; 
    cin >> password; 
    for(int i =0; i< wizardsize; i++ ){
    if(atoi(username.c_str()) == wizard1[i].id && password == wizard1[i].password) {
      cout << "Welcome : " << wizard1[i].name << "\n" << "ID: " << wizard1[i].id << "\n" << "Status: " << wizard1[i].position_title
      << "\n" << "Beard Length: " << wizard1[i].beard_length << endl;
     testval = 1 ;
     break;  
    }
    } 
    if(testval == 0){  
     cout << "Incorrect password and username." << endl; 
     counter++;
     cout << counter << endl; 
     testval = 0;
    }
    if(counter == 3){
      cout << "To many login in attempts. Please try again later. " << endl; 
      exit(3); 
    }
  } while (counter <= 3 && testval == 0 );
}
void delete_info(wizard** wizard1,int wizardsize){
   delete [] (*wizard1); 
        (*wizard1) = NULL;
}
void delete_info2( spellbook ** spellb,  int spellbooksize){
   delete [] (*spellb); 
        (*spellb) = NULL;
} 
#include "linked_list.h"
#include "node.h"
#include <iostream> 
/*******************************************************************
 * ** Function: Linked_List
 * ** Description:  default consturctor. Initializes all values  
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Linked_List::Linked_List(){
   head = NULL; 
   insertnode = new Node; 
   
}
// Linked_List::~Linked_List(){
//     delete insertnode; 
// }

/*******************************************************************
 * ** Function: get_length()
 * ** Description:  gets the length of the linked list 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/

int Linked_List::get_length(){
   int counter = 0; 
    Node* current = head; 
    while(current != NULL ){
        counter++; 
        current = current->next; 
    }
   return counter; 
}
/*******************************************************************
 * ** Function: print()
 * ** Description: prints all the values within your linked list 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::print(){
    Node* current = head; 
    while(current != NULL ){
        cout << current->val << endl; 
        current = current->next; 
    }
}
// void Linked_List::clear(){
//     //delete entire linked list 
//     //removes all nodes 
//     Node* current = head; 
//     Node* deletenodes = NULL; 
//     while(current != NULL){
//        // cout << current->val << endl; 
//         deletenodes = current; 
//         current = current->next;  
//         if(deletenodes != NULL){
//             deletenodes->next = NULL; 
//             delete deletenodes; 
//             cout << "testing" << endl; 
//         }
//     }
//     head = NULL; 
//     delete current; 
//     // if(head == NULL){
//     //     cout << "TEST " << endl; 
//     // }
//     if(deletenodes == NULL){
//         cout << "new test" << endl; 
//     }
//     // length = 0; //reseting length to zero 

// }
/*******************************************************************
 * ** Function: clear()
 * ** Description: Deletes all the nodes within your linked list and sets the length back to zero 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::clear(){
    Node* current = head; 
    Node* deletenodes = NULL;
    while(current != NULL){
        deletenodes = current->next; 
        delete current; 
        current = deletenodes; 
    } 
    head = NULL; 
}
/*******************************************************************
 * ** Function:push_front(int)
 * ** Description:inserts a value into the front of the linked list 
 * ** Parameters:(int val)-> the value you are inserting to the front of your linked lis t
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::push_front(int nvalue){
    Node* front = new Node;  // allocate memory for  a new node  
    front->val = nvalue; // assigns the value to the node 
    front->next = head; // makes the node the first value in the linked list 
    head = front;  // resets head to the first pointer
    length++; 

}
/*******************************************************************
 * ** Function:push_back(int)
 * ** Description: Inserts a value to the back of the linked list 
 * ** Parameters:int value-> the number being inserted into your linked list 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::push_back(int endvalue){
    Node* back = new Node;  // allocate memory for a new node
    Node* current = head; 
    back->next = NULL; // back is the end value 
    back->val = endvalue;
    if(head == NULL){
        head = back; 
    } 
    while(current->next != NULL){ //checking all values in the linked list untill you reach the end 
        current = current->next; 
    }
    current->next = back; //last position in node 
    length++; 
}
/*******************************************************************
 * ** Function: insert(int,unsigned int)
 * ** Description: This function inserts  a value to a specific index within your linked list 
 * ** Parameters:(int val, unsigned int index) 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::insert(int val, unsigned int index){
    Node* current = head;
     //if index is greater  than get length return 0
     if(index == get_length()){
         push_back(val);  // You must add a value to the linked list 
     }
     else if(index > get_length()){
         return;  // the desired index is not within the indexes of the linked lis t
     }
     else if(index == 0){
         push_front(val);  // the index must be greater than 0 
     }
     else{  // if index is within the size of the linked list add the value to the specified location
        insertnode->next = NULL; 
        insertnode->val = val; 
        for(int i = 0; i< index-1; i++){
            current = current->next; 
        }
        insertnode->next = current->next; 
        current->next = insertnode; 
     }  
     
}
/*******************************************************************
 * ** Function:msort2
 * ** Description: Recursive function to sort linked list. 
 * ** Parameters: Head node. 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::msort2(Node ** headtest){
   // https://www.geeksforgeeks.org/merge-sort-for-linked-list/
    Node* head = *headtest; 
    Node* rightlist ; 
    Node* leftlist ; 

    if(head == NULL || head->next == NULL){
        return; 
    }
    
    splitlist(head, &rightlist, &leftlist);
     
     msort2(&rightlist);
     msort2(&leftlist); 
    *headtest = sortedmerge(rightlist,leftlist);  
}
/*******************************************************************
 * ** Function:sortedmerge(Node*, Node*)
 * ** Description: Merges the seperated and sorted linked list into one sorted linked list 
 * ** Parameters: Right half of the linked list and the left half of the linked list 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Node* Linked_List::sortedmerge(Node* rightlist, Node* leftlist){
    Node * temp = NULL ; 

    if(rightlist == NULL){ 
        return leftlist; 
    }
    if(leftlist == NULL){
        return rightlist; 
    }
    if(rightlist->val <= leftlist->val){
        temp = rightlist; 
        temp->next = sortedmerge(rightlist->next,leftlist);
    }
    else{
        temp = leftlist; 
        temp->next = sortedmerge(rightlist, leftlist->next); 
    }
    return temp; 

}
/*******************************************************************
 * ** Function: splitlist()
 * ** Description: splits the linked list into two temperary seperate linked list . 
 * ** Parameters: the head of the linked list, right half of linked list, left half of linked list 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::splitlist(Node* head, Node** rightlist , Node** leftlist){
   Node* temp1 ;
    Node* temp2; 

    if(head== NULL || head->next == NULL){ // Base case: only one value in linked list or no values in linked list 
        *rightlist = head ;  // the linked list is not split up 
        *leftlist = NULL; 
    }
    else{ // if their is more than one value in the linked list split the list in two. 
        temp2 = head;  // starts at first element
        temp1 = head->next;  //starts at second element 
        while(temp1 !=  NULL){ // looping through all elements in the second half
            temp1 = temp1->next; //keep moving 
            if(temp1 != NULL){ //since the "fast" pointer is ahead of the slow pointer you only need to error handle that one 
                temp2 = temp2->next;  //continue to move 
                temp1 = temp1->next; 
            }
        }
    }

    *rightlist= head; //right half is from the head to the middle 
    *leftlist = temp2->next; // the left half is from the middle to null 
    temp2->next = NULL;   
   
   
}
/*******************************************************************
 * ** Function: sort_ascending
 * ** Description:calls a private merge sort function. Algorithms is from geeksforgeeks.
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::sort_ascending(){
  //  must use recursion algorithm 
  //https://www.geeksforgeeks.org/merge-sort-for-linked-list/ is where I got the algorithm 

        msort2(&head); 
  

}
/*******************************************************************
 * ** Function:msort_descending
 * ** Description: Recursive function to sort linked list. 
 * ** Parameters: Head node. 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::msort_descending(Node ** headtest){
    //recusive function 
    Node* head = *headtest; 
    Node* rightlist ; 
    Node* leftlist ; 

    if(head == NULL || head->next == NULL){ // base case with only one element in the linked list you only return that value
        return; 
    }
    
    splitlist_descending(head, &rightlist, &leftlist); //splitting the linked list into two seperate pieces 
     
     //recursive elements being used 
     msort_descending(&rightlist);  //sorting right side in descending order 
     msort_descending(&leftlist);  //sorting left side in descending order 
    *headtest = sortedmerge_descending(rightlist,leftlist);  
}
/*******************************************************************
 * ** Function:sortedmerge_descending(Node*, Node*)
 * ** Description: Merges the seperated and sorted linked list into one sorted linked list 
 * ** Parameters: Right half of the linked list and the left half of the linked list 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
Node* Linked_List::sortedmerge_descending(Node* rightlist, Node* leftlist){
    Node * temp = NULL ;  // temporary array to store the merged linked lists 

    if(rightlist == NULL){ // Error handling the linked list cannot be broken into two halves. Only return the half that exists 
        return leftlist; 
    }
    if(leftlist == NULL){ // Error handling the linked list cannot be broken into two halves. Only return the half that exists
        return rightlist; 
    }
    if(rightlist->val >= leftlist->val){ // sorting in descending order if the right half has a greater value than the left 
        temp = rightlist; 
        temp->next = sortedmerge_descending(rightlist->next,leftlist); 
    }
    else{ // sorting in descending order if the left half has a greater value than the right half. 
        temp = leftlist; 
        temp->next = sortedmerge_descending(rightlist, leftlist->next); 
    }
    return temp;  //return the temporay array with the merged lists 
}
/*******************************************************************
 * ** Function: splitlist_descending()
 * ** Description: splits the linked list into two temperary seperate linked list . 
 * ** Parameters: the head of the linked list, right half of linked list, left half of linked list 
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::splitlist_descending(Node* head, Node** rightlist , Node** leftlist){
    Node* fast ;
    Node* slow ; 

    if(head== NULL || head->next == NULL){ // Base case: only one value in linked list or no values in linked list 
        *rightlist = head ;  // the linked list is not split up 
        *leftlist = NULL; 
    }
    else{ // if their is more than one value in the linked list split the list in two. 
        slow = head;  // starts at first element
        fast = head->next;  //starts at second element 
        while(fast !=  NULL){ // looping through all elements in the second half
            fast = fast->next; //keep moving 
            if(fast != NULL){ //since the "fast" pointer is ahead of the slow pointer you only need to error handle that one 
                slow = slow->next;  //continue to move 
                fast = fast->next; 
            }
        }
    }

    *rightlist= head; //right half is from the head to the middle 
    *leftlist = slow->next; // the left half is from the middle to null 
    slow->next = NULL;   
   
}
/*******************************************************************
 * ** Function: sort_descending 
 * ** Description:calls a private merge sort function. Algorithms is from geeksforgeeks.
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
void Linked_List::sort_descending(){
    //https://www.geeksforgeeks.org/merge-sort-for-linked-list/ is where the algorthim is from
    msort_descending(&head); 
}
/*******************************************************************
 * ** Function: count_prime
 * ** Description: if the bool prime_num returns true the counter variable increase. This is within a while loop that iterates through the whole linked list 
 * ** Parameters:none  
 * ** Pre-conditions: none 
 * ** Post-conditions: none
 * *******************************************************************/
unsigned int Linked_List::count_prime(){
    int primecounter = 0; 
    Node* current = head; 
    while(current != NULL){ //checks all the values within the linked list 
        bool testval = prime_num(current->val); 
        if(testval == 1){ // if prime_num returns true indicates its a prime value 
            primecounter++;  //increase ocunter by one 
        }
        current = current->next; 
    }
    return primecounter; 
}
/*******************************************************************
 * ** Function: bool prime_num(int)
 * ** Description: If the value is prime it returns true else it returns false
 * ** Parameters: int num-> a value from your linked list  
 * ** Pre-conditions: none 
 * ** Post-conditions: prints out true or false based on if its a prime number 
 * *******************************************************************/

bool Linked_List::prime_num(int num){ 
    if(num >= 1){ // prime number is greater than 1 
        if(num %2 != 0){
            if(num %3 != 0){
                        return true;
             }
        }
    }
    return false;               
}

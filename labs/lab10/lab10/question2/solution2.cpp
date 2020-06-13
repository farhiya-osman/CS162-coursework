#include <iostream>

#include "list.h"
using namespace std; 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //Type your answer here:
    if(n>0){
      ListNode*first = head; 
      ListNode*current = head; 
      for(int i = 0 ; i<n; i++){
          if(current->next == NULL){
              if(i == n-1){
                head = head->next;
              } 
            return head; 
          }
          current = current->next; 
      }
      while(current->next != NULL){
          first = first->next; 
          current = current -> next; 
      }
      first->next = first->next->next; 
      return head; 
    }
    else{
        cout << "N is not a valid integer " << endl; 
    }
}

#include<iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    //Floyd's cycle finding algorithm: fast ptr & slow ptr
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast != NULL ){
             if(fast->next!=NULL){
                fast = fast->next->next;
             }else{
                 break;
             }
             slow = slow->next;
             if(fast == slow){
                 return true;
             }
        }
        return false;  
    }
};
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //iterative
    /*ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode*curr = head;
        ListNode*before = NULL;
        ListNode*after = head->next;
        while(curr!=NULL){
            curr->next = before;
            before = curr;
            curr = after;
            if(after!=NULL){
                after = after->next;
            }
         }
        return before;      
    }
};*/
    
    //recursive
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* top = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return top;
    }
};
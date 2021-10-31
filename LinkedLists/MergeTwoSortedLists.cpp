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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1 == NULL && l2!=NULL){
            return l2;
        }
        else if(l2 == NULL && l1!=NULL){
            return l1;
        }
        ListNode* node =NULL;
        if(l1->val <= l2->val){
            node = mergeTwoLists(l1->next,l2);
            l1->next = node;
            return l1;
        }
        else{
            node = mergeTwoLists(l1,l2->next);
            l2->next = node;
            return l2;
        }
    }
};
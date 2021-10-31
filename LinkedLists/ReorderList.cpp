#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stack>
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL)
        {
            return;
        }
        stack<ListNode *> reverse;
        ListNode *temp = head;
        while (temp != NULL)
        {
            reverse.push(temp);
            temp = temp->next;
        }
        ListNode *one = head;
        ListNode *two = head->next;
        temp = reverse.top();
        while (one != temp && one->next != temp)
        {
            one->next = temp;
            temp->next = two;
            reverse.pop();
            temp = reverse.top();
            one = two;
            two = two->next;
        }
        if (one->next == temp)
        {
            temp->next = NULL;
        }
        else
        {
            one->next = NULL;
        }
    }
};
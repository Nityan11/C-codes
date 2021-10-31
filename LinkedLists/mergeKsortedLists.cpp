#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        else if (l1 == NULL && l2 != NULL)
        {
            return l2;
        }
        else if (l2 == NULL && l1 != NULL)
        {
            return l1;
        }
        ListNode *node = NULL;
        if (l1->val <= l2->val)
        {
            node = merge(l1->next, l2);
            l1->next = node;
            return l1;
        }
        else
        {
            node = merge(l1, l2->next);
            l2->next = node;
            return l2;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;

        for (int i = lists.size(); i > 1; i = ceil((float)i / 2))
        {
            int j = 0;
            while (j < i / 2)
            {
                lists[j] = merge(lists[j], lists[i - j - 1]);
                j++;
            }
        }
        return lists[0];
    }
};
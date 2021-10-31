#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        if (p->val == q->val)
        {
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            {
                return true;
            }
            return false;
        }
        return false;
    }
};
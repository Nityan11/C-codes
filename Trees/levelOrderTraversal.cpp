#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> pending;
        pending.push(root);
        pending.push(NULL);
        vector<int> m;
        
        while(!pending.empty()){
            TreeNode* node = pending.front();
            pending.pop();
            if(node == NULL){
                ans.push_back(m);
                if(pending.empty()){
                    break;
                }
                m.clear();
                pending.push(NULL);
                continue;
            }
            m.push_back(node->val);
            
            if(node->left!=NULL){
                
                pending.push(node->left);
            }
            if(node->right!=NULL){
                
                pending.push(node->right);
            }
        }
        return ans;
    }
};
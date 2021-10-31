#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> product;
        int fwd = 1;
        product.push_back(1);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            fwd = fwd * nums[i];
            product.push_back(fwd);
        }
        int bwd = 1;
        int j = product.size() - 2;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            bwd = bwd * nums[i];
            product[j] = product[j] * bwd;
            j--;
        }
        return product;
    }
};
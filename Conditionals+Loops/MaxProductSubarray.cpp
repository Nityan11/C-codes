#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int maxp = nums[0];
        int minp = nums[0];
        int maxPro = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(maxp, minp);
            }

            maxp = max(nums[i], nums[i] * maxp);
            minp = min(nums[i], nums[i] * minp);

            if (maxPro < maxp)
            {
                maxPro = maxp;
            }
        }
        return maxPro;
    }
};
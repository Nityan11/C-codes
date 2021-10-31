#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        long int area = INT_MIN;
        while (left < right)
        {
            long int ar = min(height[left], height[right]) * (right - left);
            if (ar > area)
            {
                area = ar;
            }
            if (height[left] < height[right])
            {
                left++;
            }
            else if (height[right] < height[left])
            {
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }
        return area;
    }
};
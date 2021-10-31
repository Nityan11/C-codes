#include <iostream>
#include <vector>
using namespace std;

class MaxSumSubArrayOfSizeK
{
public:
    static int findMaxSumSubArray(int k, const vector<int> &arr)
    {
        if (arr.size() < k)
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int maxSum = 0;
        int sum = 0;
        for (; j < k; j++)
        {
            sum = sum + arr[j];
        }
        if (sum > maxSum)
        {
            maxSum = sum;
        }

        while (j < arr.size())
        {
            sum = sum - arr[i] + arr[j];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
            j++;
            i++;
        }
        return maxSum;
    }
};
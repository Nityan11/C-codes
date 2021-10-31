#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {//kadane's algo
        int sum_till_now = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum_till_now += nums[i];
            if(sum_till_now > max_sum){
                max_sum = sum_till_now;
            }
            if(sum_till_now<0){
                sum_till_now = 0;
            }
        }
        return max_sum;
    }
};
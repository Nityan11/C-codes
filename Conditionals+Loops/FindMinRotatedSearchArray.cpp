#include<iostream>
#include<vector>
using namespace std;
//binary search approach: O(logn) time complexity

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        if(nums.size()==1){
            return nums[0];
        }
        int min;
        int start = 0;
        int end = nums.size()-1;
        while(true){
            int mid = (start+end)/2;
            if(nums[mid]>=nums[0]){
                if(nums[mid]>nums[mid+1]){
                   min = nums[mid+1]; 
                   break;
                }
                start = mid+1;
            }
            else if(nums[mid]<nums[0]){
                if(nums[mid]<nums[mid-1]){
                    min = nums[mid];
                    break;
                }
                end = mid-1;
            }
        }
        return min;
    }
};
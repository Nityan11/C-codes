#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    int binarysearch(vector<int>& nums,int target,int begin, int end){
        while(begin<=end){
            int mid = (begin+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                begin = mid+1;
            }
        }
        return -1;
        
    }
    
    
    int search(vector<int>& nums, int target) {
        if(nums[0]<=nums[nums.size()-1]){
            return binarysearch(nums,target,0,nums.size()-1);
        }
        else{
            int min;
            int start = 0;
            int end = nums.size()-1;
            while(true){
                int mid = (start+end)/2;
                if(nums[mid]>=nums[0]){
                    if(nums[mid]>nums[mid+1]){
                       min = mid+1; 
                       break;
                    }
                    start = mid+1;
                }
                else if(nums[mid]<nums[0]){
                    if(nums[mid]<nums[mid-1]){
                        min = mid;
                        break;
                    }
                    end = mid-1;
                }
            }
            if(target == nums[0]){
                return 0;
            }
            else if(target<nums[0]){
                return binarysearch(nums, target,min,nums.size()-1);
            }
            else{
                return binarysearch(nums, target,0,min-1);
            }
        }
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        //size<3 not even 1 triplet possible
        if(nums.size() < 3){
            return ans; 
        }
        sort(nums.begin(), nums.end());
        //If smallest number is positive or zero, then no possiblity of having triplets
        if(nums[0]>0){
            return ans;
        }

        //complexity:O(n^2) : two pointer method

        for(int i = 0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i - 1])  continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == 0){
                    vector<int> elem;
                    elem.push_back(nums[i]);
                    elem.push_back(nums[j]);
                    elem.push_back(nums[k]);
                    ans.push_back(elem);
                    //Checking for duplicate j's
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    //Checking for duplicate k's
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++,k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
        
    }
};
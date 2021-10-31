#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> differences;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(differences.count(target-nums[i])>0){
                ans.push_back(differences[target-nums[i]]);
                break;
            }
            differences[nums[i]] = i;
        }
        ans.push_back(i);
        return ans;
    }
};
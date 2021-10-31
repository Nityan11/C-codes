#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>  map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        unordered_map<int, int>::iterator it;
        it = map.begin();
        while(it!=map.end()){
            if(it->second>1){
                return true;
            }
            it++;
        }
        return false;
    }
};
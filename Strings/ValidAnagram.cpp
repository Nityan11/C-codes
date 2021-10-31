#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1,map2;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0; i<s.size(); i++){
            map1[s[i]]++;
        }
        for(int i = 0;i<t.size();i++){
            map2[t[i]]++;
            
        }
        for(int i = 0;i<t.size();i++){
            if(map1[t[i]] != map2[t[i]]){
                return false;
            }
        }
        return true;
        
    }
};
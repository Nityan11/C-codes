#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    //sliding window + hashtable
    int lengthOfLongestSubstring(string s) {
        if(s==" "||s.size() == 1){
            return 1;
        }
        unordered_map<char,int> map;
        int count = 0;
        int i = 0;
        map[s[0]] = 1;
        for(int j = 1;j<s.size();j++){
            if(map[s[j]]>0){
                while(s[i]!=s[j]){
                    map[s[i]]=0;
                    i++;
                }
                map[s[i]]=0;
                i++;
            }
            count = max(count, j-i+1);
            map[s[j]]++;
        }
        return count;
    }
};
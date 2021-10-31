
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*string sorte(string s){
        int alpha[26]= {0};
        for(int i = 0; i<s.size(); i++){
            alpha[s[i]-95]++;
        }
        s = "";
        for(int i = 0; i<26;i++){
                while(alpha[i]>0){
                    s = s + (char)(95+i);
                    alpha[i]--;
                }
        }
        return s;
    }*/
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        if (strs.size() == 0)
        {
            return ans;
        }
        vector<string> extra;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            extra.push_back(s);
        }
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < extra.size(); i++)
        {
            if (map.count(extra[i]))
            {
                map[extra[i]].push_back(strs[i]);
            }
            else
            {
                vector<string> v;
                v.push_back(strs[i]);
                map[extra[i]] = v;
            }
        }
        unordered_map<string, vector<string>>::iterator it = map.begin();
        while (it != map.end())
        {
            ans.push_back(it->second);
            it++;
        }

        return ans;
    }
};

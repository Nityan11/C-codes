#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() == 0 || t.size() == 0 || t.size() > s.size())
        {
            return "";
        }
        int count = 0;
        unordered_map<char, int> tmap;
        for (int i = 0; i < t.size(); i++)
        {
            tmap[t[i]]++;
        }
        //filtered s
        vector<pair<char, int>> filter;
        for (int i = 0; i < s.size(); i++)
        {
            if (tmap.count(s[i]))
            {
                pair<char, int> p(s[i], i);
                filter.push_back(p);
            }
        }
        int minlength = INT_MAX;
        string ans;
        int i = 0;
        int j = 0;

        while (j < filter.size())
        {

            tmap[filter[j].first]--;
            if (tmap[filter[j].first] >= 0)
            {
                count++;
            }

            while (count == t.size())
            {
                if (filter[j].second - filter[i].second + 1 < minlength)
                {
                    minlength = filter[j].second - filter[i].second + 1;
                    ans = s.substr(filter[i].second, minlength);
                }
                //if(tmap.count(filter[i].first)) {
                tmap[filter[i].first]++;
                if (tmap[filter[i].first] > 0)
                {
                    count--;
                }
                //}
                i++;
            }

            j++;
        }

        return ans;
    }
};

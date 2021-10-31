#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int start = 0;
        int maxrepeat = 0;
        int maxlength = 0;
        unordered_map<char, int> freq;
        for (int j = 0; j < s.size(); j++)
        {
            freq[s[j]]++;
            maxrepeat = max(maxrepeat, freq[s[j]]);
            if ((j - start + 1 - maxrepeat) > k)
            {
                freq[s[start]]--;
                start++;
            }
            maxlength = max(maxlength, j - start + 1);
        }
        return maxlength;
    }
};
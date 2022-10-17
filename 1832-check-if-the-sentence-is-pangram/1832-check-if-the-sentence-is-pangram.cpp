class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;
        int n = sentence.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(mp[sentence[i]] == 0){
                cnt++;
            }
            mp[sentence[i]]++;
        }
        if(cnt == 26)return true;
        return false;
    }
};
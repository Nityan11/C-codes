class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string temp = countAndSay(n-1);
        int s = temp.size(), cnt = 1;
        string ans = "";
        for(int i = 1; i<s; i++){
            if(temp[i] == temp[i-1]){
                cnt++;
            }
            if(temp[i]!=temp[i-1]){
                
                string t = to_string(cnt);
                ans = ans + t;
                ans.push_back(temp[i-1]);
                cnt = 1;
            }
        }
        
        string t = to_string(cnt);
        ans = ans + t;
        ans.push_back(temp[s-1]);
        cnt = 1;
        return ans;
    }
};
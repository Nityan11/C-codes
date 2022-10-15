int dp[101][27][101][101];
class Solution {
public:
    
    
    int helper(int ind, int prev, int len, int k, string& s){
        if(k<0) return INT_MAX;
        if(ind>=s.size()) return 0;
         if(dp[ind][prev][len][k] != -1)
        {
            return dp[ind][prev][len][k];
        }
        //delete
        int del = helper(ind+1, prev, len, k-1, s);
        int keep = 0;
        if(s[ind]-'a' == prev){
            if(len == 1 || len == 9 || len == 99){
                keep++;
            }
            keep += helper(ind+1, prev, len+1, k, s);
        }else{
            keep = 1 + helper(ind+1, s[ind]-'a', 1, k, s);
        }
        
        dp[ind][prev][len][k] = min(del,keep);
        return dp[ind][prev][len][k];
        
        
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(0,26,0,k,s);
    }
};
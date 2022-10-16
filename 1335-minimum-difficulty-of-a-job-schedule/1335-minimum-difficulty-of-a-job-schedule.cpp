int dp[301][11];
class Solution {
public:
    int helper(vector<int>& diff, int d, int i){
        if(d==0 ){
            if(i == diff.size()){
                return 0;
            }
            int maxi = INT_MIN;
            while(i<diff.size()){
                maxi = max(maxi, diff[i]);
                i++;
            }
            return maxi;
        }
        if(i == diff.size()){
            return 30001;
        }
        if(dp[i][d] != -1){
            return dp[i][d];
        }
        int h1 = INT_MAX,h2 = INT_MIN;
        for(int j =i; j<diff.size(); j++){
            h2 = max(diff[j],h2);
            h1 = min(helper(diff, d-1, j+1)+h2,h1);
        }
        dp[i][d] = h1;
        return h1;
    }
    
    int minDifficulty(vector<int>& diff, int d) {
        int n = diff.size();
        memset(dp, -1, sizeof(dp));
        if(n<d){
            return -1;
        }
        return helper(diff, d, 0);
        
    }
};
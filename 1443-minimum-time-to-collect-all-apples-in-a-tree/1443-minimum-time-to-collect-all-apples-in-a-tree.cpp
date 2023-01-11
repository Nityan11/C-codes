class Solution {
public:
    int helper(vector<vector<int>>& list, vector<bool>& hasApple, int i, int p){
        // if(list[i].size()==1 && list[i][0] == p){
        //     if(hasApple[i]){
        //         return 1;
        //     }else{
        //         return 0;
        //     }
        // }
        int ans = 0;
        for(int j = 0; j<list[i].size(); j++){
            if(list[i][j] == p)continue;
            ans += helper(list, hasApple,list[i][j], i);
        }
        if((hasApple[i] || ans>0) && i!=0){
            ans++;
        }
        return ans;
        
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //constructing an adjacency list
        vector<vector<int>> adjlist(n);
        for(int i = 0; i<edges.size(); i++){
            adjlist[edges[i][0]].emplace_back(edges[i][1]);
            adjlist[edges[i][1]].emplace_back(edges[i][0]);
        }
        
        //calling helper
        return 2*helper(adjlist, hasApple, 0, -1);
        
    }
};
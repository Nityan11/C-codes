class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;
        
        int area = 1 + dfs(grid, i+1, j) + dfs(grid, i, j+1) + dfs(grid, i-1, j) + dfs(grid, i, j-1);
        return area;
    }
   
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i = 0; i<m; i++){
           if(grid[i][0] == 1){
               dfs(grid, i, 0);
           }
            if(grid[i][n-1] == 1){
                dfs(grid, i, n-1);
            }
        }
        for(int j = 0; j<n; j++){
           if(grid[0][j] == 1){
               dfs(grid, 0, j);
           }
            if(grid[m-1][j] == 1){
                dfs(grid, m-1, j);
            }
        }
        for(int i =1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(grid[i][j] == 1){
                    count += dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0){
            return ans;
        }
        int r1 = 0;
        int c1 = 0;
        int r2 = matrix.size()-1;
        int c2 = matrix[0].size()-1;
        
        while(r1<=r2 && c1<=c2){
            
            for(int j = c1; j<=c2; j++){
                ans.push_back(matrix[r1][j]);
            }
            for(int i = r1+1; i<=r2; i++){
                ans.push_back(matrix[i][c2]);
            }
            if(r1<r2 && c1<c2){
                for(int j = c2-1; j>=c1; j--){
                    ans.push_back(matrix[r2][j]);
                }
                for(int i = r2-1; i>r1; i--){
                    ans.push_back(matrix[i][c1]);
                }
            }
            r1++;
            c1++;
            r2--;
            c2--;
        }
        return ans;
    }
};
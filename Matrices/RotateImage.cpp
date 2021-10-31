#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //transpose ->reflect ->image
    void transpose(vector<vector<int>>& matrix){
        for(int i = 0; i<matrix.size();i++){
            for(int j = 0; j<matrix.size(); j++){
                if(i<j){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
    }
    
    void reflect(vector<vector<int>>& matrix){
            for(int i = 0; i<matrix.size(); i++){
                for(int j = 0; j<matrix.size()/2; j++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][matrix.size()-j-1]; 
                    matrix[i][matrix.size()-j-1] = temp;
                }
            }
    }
        
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }
};
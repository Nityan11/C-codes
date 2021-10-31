#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    //  O(1) space & O(mn) time
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = 0;
        int col = 0;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
                row = 1;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                col = 1;
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0 && j != 0)
            {
                for (int i = 1; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0 && i != 0)
            {
                for (int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row == 1)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col == 1)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
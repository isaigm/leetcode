// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1;
        int j = 0;
        while(i != 0 || j != n - 1)
        {
            int last_value = matrix[i][j];
            for(int r = i, c = j; r < m && c < n; r++, c++)
            {
                if(last_value != matrix[r][c]) return false;
                last_value = matrix[r][c];
            }
            if(i == 0)
            {
                j++;
                
            }else
            {
                i--;
            }
        }
        return true;
    }
};
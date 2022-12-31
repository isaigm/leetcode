// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> ans;
        int r = 0, c = 0;
        bool dir = true;
        while(r != rows - 1 || c != cols - 1)
        {
            if(dir)
            {
                for(; r >= 0 && c < cols; r--, c++){
                    ans.push_back(matrix[r][c]);
                }
                r++;
                c--;
                if(c + 1 < cols){
                    c++;
                }else{
                    r++;
                }
                
            }else{
                for(; r < rows && c >= 0; r++, c--)
                {
                    ans.push_back(matrix[r][c]);
                }
                r--;
                c++;
                if(r + 1 < rows){
                    r++;
                }else{
                    c++;
                }
            }
            dir = !dir;
        }
        ans.push_back(matrix[rows - 1][cols - 1]);
        return ans;
        
    }
};
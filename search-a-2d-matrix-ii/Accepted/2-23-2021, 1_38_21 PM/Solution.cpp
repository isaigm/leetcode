// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int rows = matrix.size();
        for(int i = 0; i < rows; i++)
        {
            auto found = std::binary_search(matrix[i].begin(), matrix[i].end(), target);
            if(found) return true;
        }
        return false;
    }
};
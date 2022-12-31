// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(matrix.size() > 0 && matrix[0].size() > 0){
        for(const auto &row: matrix){
            auto min = row[0];
            if(target >= min){
                auto flag = std::binary_search(row.begin(), row.end(), target);
                if(flag) return true;
            }else return false;
        }
        return false;
    }
    return false;
    }
};
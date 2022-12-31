// https://leetcode.com/problems/rotate-image

class Solution {
public:
   void rotate(std::vector<std::vector<int>>& matrix) {
     auto n = matrix.size();
    for(size_t i = 0; i <= n - 2; i++){
        for(size_t j = i + 1; j <= n - 1; j++){
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    size_t left = 0;
    size_t right = n - 1;
    while (left < right) {
        for(size_t i = 0; i < n; i++){
            std::swap(matrix[i][left], matrix[i][right]);
        }
        left++;
        right--;
    }
}
};
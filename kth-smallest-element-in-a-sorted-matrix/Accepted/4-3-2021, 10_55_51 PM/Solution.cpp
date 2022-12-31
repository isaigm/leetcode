// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int, std::vector<int>> heap;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                heap.push(matrix[i][j]);
                if(heap.size() > k)
                {
                    heap.pop();
                }
            }
        }
        return heap.top();
    }
};
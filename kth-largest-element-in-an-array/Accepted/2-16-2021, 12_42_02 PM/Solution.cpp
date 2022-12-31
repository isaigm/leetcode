// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for(auto n: nums)
        {
            heap.push(n);
            if(heap.size() > k)
            {
                heap.pop();
            }
        }
        return heap.top();
        
    }
};
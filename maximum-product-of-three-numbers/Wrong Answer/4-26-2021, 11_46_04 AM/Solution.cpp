// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        
        return nums[size - 1] * nums[size - 2] * nums[size - 3];
    }
};
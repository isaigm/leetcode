// https://leetcode.com/problems/array-partition

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2)
        {
            sum += std::min(nums[i], nums[i + 1]);
        }
        return sum;
    }
};
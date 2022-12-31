// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        std::vector<int> ans(nums.size());
        int left_sum = 0;
        int right_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            left_sum += nums[i];
            ans[i] = (i + 1) * nums[i]  - left_sum;
        }
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            right_sum += nums[i];
            ans[i] += right_sum - (nums.size() - i) * nums[i];
        }
        return ans;
    }
};

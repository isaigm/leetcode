// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> ans(nums.size());
        int curr_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans[i] = curr_sum + nums[i];
            curr_sum = ans[i];
        }
        return ans;
    }
};
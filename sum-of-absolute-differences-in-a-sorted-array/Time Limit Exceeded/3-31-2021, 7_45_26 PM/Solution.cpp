// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        std::vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                sum += std::abs(nums[i] - nums[j]);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


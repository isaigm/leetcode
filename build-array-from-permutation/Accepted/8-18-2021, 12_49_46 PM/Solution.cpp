// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        std::vector<int> ans;
        for(auto x: nums)
        {
            ans.push_back(nums[x]);
        }
            
        return ans;
    }
};
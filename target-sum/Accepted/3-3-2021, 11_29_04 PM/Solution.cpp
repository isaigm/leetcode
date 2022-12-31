// https://leetcode.com/problems/target-sum

class Solution {
public:
    void util(vector<int> &nums, int &target, int &ans, int idx, int S)
    {
        if(idx == nums.size())
        {
            if(S == target)
            {
                ans++;
                return; 
            }
        }else{
             util(nums, target, ans, idx + 1, S + nums[idx]);
         
                util(nums, target, ans, idx + 1, S - nums[idx]);
        }
       
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        util(nums, S, ans, 0, 0);
        return ans;
    }
};
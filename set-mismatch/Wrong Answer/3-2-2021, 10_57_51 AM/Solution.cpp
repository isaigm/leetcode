// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> ans(2);
        std::sort(nums.begin(), nums.end());
        bool flag = false;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i + 1])
            {
                
                ans[0] = nums[i];
            }
            else if(nums[i] != i + 1 && !flag)
            {
                flag = true;
                ans[1] = i + 1;
            }
        }
        if(nums[nums.size() - 1] != nums.size())
        {
            ans[1] = nums.size();
        }
        return ans;
    }
};
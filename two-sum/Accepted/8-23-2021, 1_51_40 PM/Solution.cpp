// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> integers;
        std::vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++)
        {
            integers[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(integers.find(target - nums[i]) != integers.end())
            {
                int idx = integers[target - nums[i]];
                if(idx != i)
                {
                    ans[0] = i;
                    ans[1] = idx;
                    break;
                }
            }
        }
        return ans;
    }
};
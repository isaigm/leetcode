// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         for(int i = 0; i < nums.size(); i++)
            {
                for(int j = i + 1; j < nums.size(); j++)
                {
                    if(abs(nums[i] - nums[j]) <= t && abs(i - j) <= k)
                    {
                        return true;
                    }
                }
            }
            return false;
    }
};
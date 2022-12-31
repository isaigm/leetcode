// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        long long int k1 = k;
        long long int t1 = t;

         for(int i = 0; i < nums.size(); i++)
            {
                for(int j = i + 1; j < nums.size(); j++)
                {
                    if(abs(nums[i] - nums[j]) <= t1 && abs(i - j) <= k1)
                    {
                        return true;
                    }
                }
            }
            return false;
    }
};
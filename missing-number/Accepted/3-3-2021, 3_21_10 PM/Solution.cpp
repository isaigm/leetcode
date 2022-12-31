// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = n * (n + 1) / 2;
        int s2 = 0;
        for(const auto &j: nums)
        {
            s2 += j;
        }
        return s1 - s2;
    }
};
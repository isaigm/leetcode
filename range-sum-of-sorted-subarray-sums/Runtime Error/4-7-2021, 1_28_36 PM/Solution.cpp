// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        std::vector<int> sums;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        std::sort(sums.begin(), sums.end());
        int ans = 0;
        for(int i = left - 1; i < right; i++)
        {
            ans += sums[i] % 1000000007;
        }
        return ans % 1000000007;
    }
};
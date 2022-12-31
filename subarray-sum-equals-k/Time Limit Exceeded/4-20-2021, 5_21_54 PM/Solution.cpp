// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::vector<int> sums(nums.size());
        sums[0] = nums[0];
        int cnt = 0;
        if(nums[0] == k) cnt++;
        for(int i = 1; i < nums.size(); i++)
        {
            sums[i]  = sums[i - 1] + nums[i];
            if(nums[i] == k) cnt++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(i > 0)
                {
                    if(sums[j] - sums[i - 1] == k) cnt++;
                }else if(sums[j] == k) cnt++;
            }
        }
        return cnt;
    }
};

    
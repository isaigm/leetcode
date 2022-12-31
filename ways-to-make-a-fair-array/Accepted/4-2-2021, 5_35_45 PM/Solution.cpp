// https://leetcode.com/problems/ways-to-make-a-fair-array

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        std::vector<int> even_sum(nums.size(), 0);
        std::vector<int> odd_sum(nums.size(), 0);
        int ans = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if((i - 1) % 2 == 0)
            {
                even_sum[0] += nums[i];
            }else
            {
                odd_sum[0] += nums[i];
            }
        }
        for(int i = 1; i < nums.size(); i++)
        {
            if(i % 2 == 0)
            {
                odd_sum[i] = odd_sum[i - 1] - nums[i] + nums[i - 1];
                even_sum[i] = even_sum[i - 1];

            }else
            {
                even_sum[i] = even_sum[i - 1] - nums[i] + nums[i - 1];
                odd_sum[i] = odd_sum[i - 1];
            }
            if(odd_sum[i] == even_sum[i]) ans++;
        }
        if(odd_sum[0] == even_sum[0]) ans++;
        return ans;
    }
};
// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        std::vector<int> sums;
        int curr_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            sums.push_back(curr_sum);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                if(sums[j] - sums[i] + nums[i] == k)
                {
                    total++;
                }
            }
        }
        
        return total;
    }
};




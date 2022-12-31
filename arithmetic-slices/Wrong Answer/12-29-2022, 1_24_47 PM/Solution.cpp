// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int sumFromOneTo(int n)
    {
        return n * (n + 1) / 2;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int last_diff = 0;
        int current_diff = 0;
        for (int i = 0; i < 2; i++)
        {
            last_diff = current_diff;
            current_diff = std::abs(nums[i + 1] - nums[i]);
        }
        int curr_len = current_diff == last_diff ? 3: 2;
        last_diff = current_diff;
        int ans = 0;
        for(int i = 3; i < nums.size(); i++)
        {
            current_diff = std::abs(nums[i] - nums[i - 1]);
            if(last_diff == current_diff)
            {
                curr_len++;
            }
            else
            {
                ans += sumFromOneTo(curr_len - 2);
                curr_len = 2;
            }
            last_diff = current_diff;
        }
        ans += sumFromOneTo(curr_len - 2);
        return ans;
    }
};
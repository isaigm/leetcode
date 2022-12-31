// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(std::abs(nums[i]) > 0)
            {
                std::swap(nums[i], nums[k]);
                k++;
            }
        }
        for(int i = k; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
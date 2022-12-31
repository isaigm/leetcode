// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        std::vector<int> ans;
        bool which_part = true;
        for(int i = 0, left = 0, right = n - 1; i < 2*n; i++)
        {
            if(which_part)
            {
                ans.push_back(nums[left]);
                right++;
            }else{
                ans.push_back(nums[right]);
                left++;
            }
            which_part = !which_part;
        }
        return ans;
    }
};
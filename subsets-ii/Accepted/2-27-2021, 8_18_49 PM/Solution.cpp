// https://leetcode.com/problems/subsets-ii

class Solution {
public:
       void util( std::vector<std::vector<int>> &ans, std::vector<int> &nums, std::vector<int> &curr, int start)
    {
           ans.push_back(curr);
           for(int i = start; i < nums.size(); i++)
           {
               if(i > start && nums[i] == nums[i-1]) continue;
               curr.push_back(nums[i]);
               util(ans, nums, curr, i + 1);
               curr.pop_back();
           }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        std::sort(nums.begin(), nums.end());
        util(ans, nums, curr, 0);
        return ans;
    }
};

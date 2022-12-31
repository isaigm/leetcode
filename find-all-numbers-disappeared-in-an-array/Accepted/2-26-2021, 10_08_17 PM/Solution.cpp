// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> ans;
        std::vector<int> aux(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++)
        {
            aux[nums[i] - 1] = nums[i];
        }
        for(int i = 0; i < aux.size(); i++)
        {
            if(aux[i] == -1)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
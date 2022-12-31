// https://leetcode.com/problems/jump-game

class Solution {
public:
void _canJump(bool &solved, int &steps, int idx, std::vector<int> &nums)
{
    
    for (int i = idx; i < nums.size() - 1; i++)
    {
        int k = nums[i];
        if(k == 0)
        {
            solved = false;
            return;
        }
            while (k > 0)
            {
                steps += k;
               
                if (steps == nums.size() - 1)
                {
                    solved = true;
                    return;
                }
                _canJump(solved, steps, steps, nums);
                if (solved)
                {
                    return;
                }
                steps -= k;
                k--;
            }
        
    }
}
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        bool solved = false;
        int steps = 0;
        _canJump(solved, steps, 0, nums);
        return solved;
    }
};
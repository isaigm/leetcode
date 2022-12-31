// https://leetcode.com/problems/jump-game

class Solution {
public:
void _canJump(int *cache, bool &solved, int &steps, int idx, std::vector<int> &nums)
{
    if(idx < nums.size() && cache[idx] != -1) 
    {
        solved = cache[idx];
        return;
    }
    for (int i = idx; i < nums.size() - 1; i++)
    {
        int k = nums[i];
        if(k == 0)
        {
            solved = false;
            cache[idx] = 0;
            return;
        }
            while (k > 0)
            {
                steps += k;
               
                if (steps == nums.size() - 1)
                {
                    solved = true;
                    cache[idx] = 1;
                    return;
                }
                _canJump(cache, solved, steps, steps, nums);
                if (solved)
                { 
                    cache[idx] = 1;
                    return;
                }
                steps -= k;
                k--;
            }
        
    }
}
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int cache[nums.size()];
        bool solved = false;
        int steps = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cache[i] = -1;
        }
        _canJump(cache, solved, steps, 0, nums);
        return solved;
    }
};
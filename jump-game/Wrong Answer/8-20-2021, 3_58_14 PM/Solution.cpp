// https://leetcode.com/problems/jump-game

class Solution {
public:
void _canJump(int *cache, bool &solved, int idx, std::vector<int> &nums)
{
    if(idx >= nums.size()) return;
    if(nums[idx] == 0) return;
    if(cache[idx] != -1) {
        solved = cache[idx];
        return;
    }
    if(idx == nums.size() - 1)
    {
        solved = true;
        cache[idx] = 1;
        return;
    }
    
    for(int i = 1; i <= nums[idx]; i++)
    {
        _canJump(cache, solved, idx + i, nums);
        if(solved)
        {
            cache[idx] = 1;
            return;
        }
    }
    cache[idx] = 0;
}
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int cache[nums.size()];
        bool solved = false;
        
        for(int i = 0; i < nums.size(); i++)
        {
            cache[i] = -1;
        }
        _canJump(cache, solved, 0, nums);
        return solved;
    }
};
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> ans(2);
        ans[0] = first_idx(nums, target);
        ans[1] = last_idx(nums, target);
        return ans;
    }
    int last_idx(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                idx = mid;
            }
            if(nums[mid] <= target)
            {
                left = mid + 1;
            }else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return idx;
    }
    int first_idx(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                idx = mid;
            }
            if(nums[mid] < target)
            {
                left = mid + 1;
            }else if(nums[mid] >= target)
            {
                right = mid - 1;
            }
        }
        return idx;
    }
};
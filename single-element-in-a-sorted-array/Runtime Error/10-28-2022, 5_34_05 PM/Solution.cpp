// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    void search(std::vector<int> &nums, int left, int right, int &ans)
{
    if (right - left + 1 == 3)
    {
        int xorr = 0;
        for (int i = left; i <= right; i++)
        {
           xorr ^= nums[i];
        }
        ans = xorr;
    }
    else
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[mid - 1] && (mid - left - 1) % 2)
        {
            search(nums, left, mid - 2, ans);
        }
        else if (nums[mid] != nums[mid-1] && (mid - left) % 2)
        {
            search(nums, left, mid - 1, ans);
        }
        else if (nums[mid] == nums[mid + 1] && (right - mid - 1) % 2)
        {
            search(nums, mid + 2, right, ans);
        }
        else if (nums[mid] != nums[mid + 1] && (right - mid) % 2)
        {
            search(nums, mid + 1, right, ans);
        }else
        {
            ans = nums[mid];
        }
    }
}
int singleNonDuplicate(std::vector<int> &nums)
{
    int ans;
    search(nums, 0, nums.size() - 1, ans);
    return ans;
}
};
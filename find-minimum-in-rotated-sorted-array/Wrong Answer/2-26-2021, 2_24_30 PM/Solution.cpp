// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[0] <= nums[nums.size() - 1]) return nums[0];
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }else if(nums[left] > nums[mid])
            {
                right = mid;
            }else{
                return nums[mid - 1];
            }
        }
        return nums[left];
    }
};

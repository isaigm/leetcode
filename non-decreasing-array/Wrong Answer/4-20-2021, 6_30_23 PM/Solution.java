// https://leetcode.com/problems/non-decreasing-array

class Solution {
     public boolean checkPossibility(int[] nums) {
        for(int i = 0; i < nums.length - 1; i++)
        {
            if(nums[i] > nums[i + 1]){
                nums[i] = nums[i + 1];
                break;
            }
        }
        for(int i = 0; i < nums.length - 1; i++)
        {
            if(nums[i] > nums[i + 1]){
                return false;
            }
        }
        return true;
    }
}
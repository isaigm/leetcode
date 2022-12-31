// https://leetcode.com/problems/non-decreasing-array

class Solution {
     public boolean checkPossibility(int[] nums) {
        int cnt = 0;
        for(int i = 0; i < nums.length - 1; i++)
        {
            if(nums[i] > nums[i + 1]) cnt++;
        }
        return cnt <= 1;
    }
}
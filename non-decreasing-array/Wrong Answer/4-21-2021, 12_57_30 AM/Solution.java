// https://leetcode.com/problems/non-decreasing-array

class Solution {
     public boolean checkPossibility(int[] nums) {
        int idx = -1;
         int last = -1;
        for(int i = 0; i < nums.length - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                idx = i;
                nums[i + 1] = nums[i];
                last = nums[i + 1];
                break;
            }
        }
         boolean flag = false;
        for(int j = 0; j < nums.length - 1; j++)
        {
            if(nums[j] > nums[j + 1] ){
                flag = true;
                break;
            }
        }
         if(!flag && idx != -1)
         {
             nums[idx] = last;
              for(int j = 0; j < nums.length - 1; j++)
        {
            if(nums[j] > nums[j + 1] ){
               return false;
            }
        }
         }
        return true;
    }
}
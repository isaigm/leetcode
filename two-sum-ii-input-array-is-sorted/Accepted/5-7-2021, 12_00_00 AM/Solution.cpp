// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        std::vector<int> ans;
        while(left < right)
        {
            int sum = numbers[right] + numbers[left];
            if(sum > target)
            {
                right--;
            }
            else if(sum < target)
            {
                left++;
            }else
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
            
        }
        return ans;
    }
};
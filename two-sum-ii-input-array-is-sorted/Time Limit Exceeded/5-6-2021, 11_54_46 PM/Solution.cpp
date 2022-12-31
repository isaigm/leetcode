// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int last_idx = numbers.size() - 1;
        std::vector<int> ans;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] > target)
            {
                last_idx = i;
                break;
            }
        }
        for(int i = 0; i <= last_idx; i++)
        {
            for(int j = i + 1; j <= last_idx; j++)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    break;
                }
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
};
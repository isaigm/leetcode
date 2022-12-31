// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int len = 0;
        for(const auto &x: nums)
        {
            if(x == 1){
                len++;
            }else{
                ans = std::max(ans, len);
                len = 0;
            }
        }
        ans = std::max(ans, len);
        return ans;
    }
};
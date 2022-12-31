// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::set<int> seen;
        for(const auto &x: nums)
        {
            if(x > 0)
            {
                seen.insert(x);
            }
        }
        for(int i = 1; i <= 2147483647; i++)
        {
            if(seen.find(i) == seen.end()) return i;
        }
        return 0;
    }
};
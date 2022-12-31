// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> seen;
        for(const auto &x: nums)
        {
            if(seen.find(x) != seen.end()) return true;
            
            seen.insert(x);
        }
        return false;
    }
};
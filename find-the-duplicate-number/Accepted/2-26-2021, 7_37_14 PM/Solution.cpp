// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::set<int> s;
        for(auto &n: nums){
            if(s.find(n) != s.end()) return n;
            s.insert(n);
        }
        return 0;
    }
};
// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int, int> frq;
        std::set<int> seen;
        for(const auto &x: arr)
        {
            frq[x]++;
        }
        for(const auto &[_, x]: frq)
        {
            if(seen.find(x) != seen.end()) return false;
            seen.insert(x);
        }
        return true;
    }
};
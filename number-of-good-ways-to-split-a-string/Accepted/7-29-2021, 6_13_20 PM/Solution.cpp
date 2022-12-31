// https://leetcode.com/problems/number-of-good-ways-to-split-a-string

class Solution {
public:
    int numSplits(string s) {
        std::map<int, int> left;
        std::map<int, int> right;
        std::set<int> uniq_left;
        std::set<int> uniq_right;
        
        
        for(int i = 0; i < s.size() - 1; i++)
        {
            uniq_left.insert(s[i]);
            
            uniq_right.insert(s[s.size() - i - 1]);
            
            right[s.size() - i - 1] = uniq_right.size();
            
            left[i] = uniq_left.size();
        }
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(left[i] == right[i + 1])
            {
                ans++;
            }
        }
        return ans;
    }
};
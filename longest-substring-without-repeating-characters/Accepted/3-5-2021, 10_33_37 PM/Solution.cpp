// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = INT_MIN;
        int left = 0;
        std::map<char, int> m;
        bool all_uniques = true;
        for(int i = 0; i < s.size(); i++)
        {
            if(m.find(s[i]) == m.end())
            {
                m[s[i]] = i;
            }else{
                all_uniques = false;
                ans = std::max(ans, i - left);
                left = m[s[i]] + 1;
                i = left - 1;
                m.clear();
            }
        }
    
        if(all_uniques) return s.size();
        if(m.find(s[s.size() - 1]) != m.end())
        {
            ans = std::max(ans, int(s.size()) - left);
        }
        return ans;
    }
};
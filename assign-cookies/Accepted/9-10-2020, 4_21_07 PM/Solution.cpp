// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        std::sort(g.begin(), g.end(), std::greater<int>());
        std::sort(s.begin(), s.end(), std::greater<int>());
        int result = 0;
        size_t idx = 0;
        for(size_t i = 0; i < g.size() && idx < s.size(); i++){
            if(s[idx] >= g[i]){
                result++;
                idx++;
            }
        }
        return result;
    }
};


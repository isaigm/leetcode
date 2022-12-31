// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int result = 0;
        size_t idx = 0;
        for(size_t i = 0; i < g.size(); i++){
            if(s[idx] >= g[i]){
                result++;
                idx++;
            }
        }
        return result;
    }
};


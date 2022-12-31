// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::set<int> seen;
        
        for(const auto &v: edges)
        {
            auto e1 = v[0];
            auto e2 = v[1];
            if(seen.find(e1) != seen.end())
            {
                return e1;
            }
            if(seen.find(e2) != seen.end())
            {
                return e2;
            }
            seen.insert(e1);
            seen.insert(e2);
        }
        return 0;
    }
};
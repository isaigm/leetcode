// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::map<int, int> frq;
        std::set<int> s;
        int curr_size = arr.size();
        for(const auto &x: arr)
        {
            frq[x]++;
        }
        std::vector<std::pair<int, int>> t;
        for(const auto [n, e]: frq)
        {
           t.push_back({n, e});
        }
        std::sort(t.begin(), t.end(), [](auto &p1, auto &p2){
            return p1.second > p2.second;
        });
        int idx = 0;
        while(curr_size > arr.size() / 2)
        {
            if(idx < t.size())
            {
                curr_size -= t[idx].second;
                idx++;
                s.insert(t[idx].first);
            }
        }
        
        return s.size();
    }
};
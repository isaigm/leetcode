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
        while(curr_size >= arr.size() / 2)
        {
            int max_frq = 0;
            int who;
            for(const auto [n, e]: frq)
            {
                if(s.find(n) == s.end())
                {
                    max_frq = std::max(max_frq, e); 
                    who = n;
                }
            }
            if(max_frq > 0)
            {
                s.insert(who);
                curr_size -= max_frq;
            }
        }
        return s.size();
    }
};
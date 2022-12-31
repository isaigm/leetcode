// https://leetcode.com/problems/sequential-digits

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> valids;
        std::vector<int> ans;
        for(int i = 1; i < 9; i++)
        {
            gen_all_valids(valids, i, i);
        }
        std::sort(valids.begin(), valids.end());
        for(const auto &x: valids)
        {
            if(x >= low && x <= high)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
    void gen_all_valids(std::vector<int> &valids, int start, int n)
    {
        if(n > 9) 
        {
            valids.push_back(n);
        }
        if(start < 9)
        {
            n = n * 10 + start + 1;
            gen_all_valids(valids, start + 1, n); 
        }
    }
};
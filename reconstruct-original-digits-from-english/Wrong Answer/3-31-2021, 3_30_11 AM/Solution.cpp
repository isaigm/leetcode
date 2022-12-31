// https://leetcode.com/problems/reconstruct-original-digits-from-english

class Solution {
public:
    string originalDigits(string s) {
        std::string ans = "";
        int tab[26] = {0};
        std::vector<std::string> digits {"zero", "one", "two", "three", "four",
                                        "five", "six", "seven", "eight", "nine"};
        std::vector<int> ds;
        for(const auto &ch: s)
        {
            tab[ch - 'a']++;
        }
        for(int i = 0; i < digits.size(); i++)
        {
            int min_times = INT_MAX;
            for(int j = 0; j < digits[i].size(); j++)
            {
                int t = tab[digits[i][j] - 'a']; 
                if(t == 0){
                    min_times = INT_MAX;
                    break;
                }
                min_times = std::min(min_times, t);
            }
            if(min_times != INT_MAX)
            {
                for(int k = 0; k < min_times; k++)
                {
                    ds.push_back(i);
                }
            }
        }
        if(ds.size() > 0){
            std::sort(ds.begin(), ds.end());
            for(const auto &d: ds)
            {
                ans += d + '0';
            }
        }
        return ans;
    }
};
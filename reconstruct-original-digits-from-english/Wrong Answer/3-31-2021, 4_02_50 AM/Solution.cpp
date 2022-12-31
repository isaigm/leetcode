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
        int sum = 0;
        for(int i = 0; i < 26; i++)
        {
            sum += tab[i];
        }
        int last_sum = -1;
        while(sum != last_sum)
        {
            last_sum = sum;
            for(int i = 0; i < digits.size(); i++)
            {
                bool flag = true;
                for(int j = 0; j < digits[i].size(); j++)
                {
                    int t = tab[digits[i][j] - 'a']; 
                    if(t <= 0){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    for(int j = 0; j < digits[i].size(); j++)
                    {
                        tab[digits[i][j] - 'a']--;
                        sum--;
                    }
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
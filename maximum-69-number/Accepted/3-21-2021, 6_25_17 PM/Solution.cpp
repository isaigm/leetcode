// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        std::string num_str = std::to_string(num);
        int ans = 0;
        bool found = false;
        for(int i = 0; i < num_str.size(); i++)
        {
            int dig = num_str[i] - '0';
            if(dig == 6 && !found)
            {
                found = true;
                num_str[i] = 9 + '0';
            }
            dig = num_str[i] - '0';
            ans += dig * std::pow(10, num_str.size() - i - 1);
        }
        return ans;
    }
};
// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    void dig(int num, std::vector<int> &digits)
    {
        if(num > 0)
        {
            dig(num / 10, digits);
            digits.push_back(num % 10);
        }
    }
    int maximumSwap(int num) {
        std::vector<int> digits;
        int ans = 0;
        dig(num, digits);
        int max_digit = 9;
        int idx = 0;
        while(true)
        {
            if(max_digit == digits[idx]) {
                idx++;
            }
            int j = -1;
            for(int i = idx + 1; i < digits.size(); i++)
            {
                if(digits[i] == max_digit)
                {
                    j = i;
                }
            }
            if(j != -1)
            {
                std::swap(digits[idx], digits[j]);
                break;
            }
            max_digit--;
        }
        for(int i = 0; i < digits.size(); i++)
        {
            ans += digits[i] * std::pow(10, digits.size() - i - 1);
        }
        return ans;
    }
};

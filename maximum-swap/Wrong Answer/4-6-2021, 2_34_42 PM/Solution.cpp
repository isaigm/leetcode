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
        auto m = std::max_element(digits.begin(), digits.end());
        int i = 0;
        while(i < digits.size() && digits[i] == *m)
        {
            if(i + 1 < digits.size())
            m = std::max_element(digits.begin() + i + 1, digits.end());
            i++;
        }
        if(i < digits.size())
        {
            std::swap(digits[i], digits[std::distance(digits.begin(), m)]);
        }
        for(int i = 0; i < digits.size(); i++)
        {
            ans += digits[i] * std::pow(10, digits.size() - i - 1);
        }
        return ans;
    }
};

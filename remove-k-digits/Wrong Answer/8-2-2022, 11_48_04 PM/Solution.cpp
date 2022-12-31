// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    //encontrar el minimo digito tal que a partir de ahi en adelante
    //sobran suficientes digitos
    //como para formar el string final
    
    std::string removeKdigits(std::string num, int k)
{

    std::string res = "";
    int last_digit_idx = 0;
    int size = num.size() - k;
    if (size == 0)
        return "0";

    bool leading_zeroes = true;
    for (int i = 0; i < size; i++)
    {
        int min_digit = INT_MAX;
        for (int j = last_digit_idx; j < num.size(); j++)
        {
            int digit = num[j] - '0';
            if (min_digit > digit && num.size() - j - 1 >= size - i - 1)
            {
                min_digit = digit;
                last_digit_idx = j + 1;
            }
        }
        if (min_digit != INT_MAX)
        {
            if(min_digit  == 0 && size == 1) return "0";
            if (min_digit > 0)
            {
                leading_zeroes = false;
            }
            if (!leading_zeroes)
            {
                res += min_digit + '0';
            }
        }
    }
    return res;
}
};


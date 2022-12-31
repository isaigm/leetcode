// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string

class Solution {
public:
    char findKthBit(int n, int k) {
        std::string s = "0";
        for(int i = 1; i < n; i++)
        {
            s += "1" + reverse_and_invert(s);
        }
        return s[k - 1];
    }
    std::string reverse_and_invert(std::string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
            {
                s[i] = '1';
            }else s[i] = '0';
        }
        std::reverse(s.begin(), s.end());
        return std::move(s);
    }
};
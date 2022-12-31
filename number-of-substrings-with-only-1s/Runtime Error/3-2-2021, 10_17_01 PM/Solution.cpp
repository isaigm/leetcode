// https://leetcode.com/problems/number-of-substrings-with-only-1s

class Solution {
public:
    int numSub(string s) {
        uint64_t count = 0;
        int idx = 0;
        int nbits = 0;
        bool flag = false;
        while(true)
        {
            while(s[idx] == '1' && idx < s.size())
            {
                nbits++;
                idx++;
                flag = true;
            }
            if(flag)
            {
                idx--;
                flag = false;
            }
            if(nbits > 0)
            {
                count += nbits * (nbits + 1) / 2;
                nbits = 0;
            }
            idx++;
            if(idx >= s.size())
            {
                break;
            }
        }
        return count % (1000000000 + 7);
    }
};

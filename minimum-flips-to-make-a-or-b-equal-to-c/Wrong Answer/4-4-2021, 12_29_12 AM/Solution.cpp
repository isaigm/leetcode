// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 1; i <= 31; i++)
        {
            int a1 = a & 1;
            int b1 = b & 1;
            if((a1 | b1) == (c & 1)) continue;
            if(c & 1)
            {
                ans++;
            }else
            {
                ans += a1 + b1;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};

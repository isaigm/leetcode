// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 0; i <= 31; i++)
        {
            if((x & 1) != (y & 1)) ans++;
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
};
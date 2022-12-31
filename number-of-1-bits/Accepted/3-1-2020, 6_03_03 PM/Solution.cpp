// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (size_t i = 0; i < 32; i++)
        {
            if(((n >> (31-i)) & 0x1) != 0) count++;
        }
        return count;
    }
};
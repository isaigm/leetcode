// https://leetcode.com/problems/xor-operation-in-an-array

class Solution {
public:
    int xorOperation(int n, int start) {
        int xorr = 0;
        for(int i = 0; i < n; i++)
        {
            int curr = start + 2 * i;
            xorr ^= curr;
        }
        return xorr;
    }
};
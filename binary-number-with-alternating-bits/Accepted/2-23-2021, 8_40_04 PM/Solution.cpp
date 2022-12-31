// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last_bit = !(n & 0x1);
        while(n > 0){
            if(last_bit != !(n & 0x1)){
                return false;
            }
            last_bit = n & 0x1;
            n >>= 1;
        }   
        return true;
    }
};
// https://leetcode.com/problems/reverse-bits

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0x0;
    int places = 32;
    uint32_t bits;
    while (n > 0)
    {
        bits = (n & 1) << ((places--) - 1);
        rev |= bits;
        n >>= 1;
    }
    return rev;
    
}
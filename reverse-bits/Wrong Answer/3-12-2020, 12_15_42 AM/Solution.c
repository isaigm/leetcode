// https://leetcode.com/problems/reverse-bits

int countBits(uint32_t n){
    int count = 0;
    while (n > 0)
    {
        n >>= 1;
        count++;
    }
    return count;
    
}
uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0x0;
    int places = countBits(n);
    char bit;
    while (n > 0)
    {
        bit = (n & 1) << ((places--) - 1);
        rev |= bit;
        n >>= 1;
    }
    return rev;
    
}
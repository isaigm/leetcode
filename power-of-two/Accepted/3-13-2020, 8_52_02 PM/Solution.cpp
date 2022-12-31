// https://leetcode.com/problems/power-of-two

class Solution {
public:
  bool isPowerOfTwo(int n) {
    auto counting_bits = [](int k) -> int{
        int c = 0;
        while (k > 0)
        {
            if(k & 1) c++;
            k >>= 1;
        }
        return c;
    };        
    if (counting_bits(n) == 1) return true;
    return false;
}
};
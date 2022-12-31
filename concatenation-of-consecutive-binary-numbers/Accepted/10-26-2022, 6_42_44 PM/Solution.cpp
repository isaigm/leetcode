// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
uint64_t concatenatedBinary(int n)
{
    if (n == 1) return 1;
    uint64_t curr = 1;
    for (int i = 2; i <= n; i++)
    {
        uint64_t temp = curr << (int(log2(i)) + 1);
        temp = (temp + i) % 1000000007;
        curr = temp;
    }
    return curr;
}
   
    
};      
//1 10 11 100
//f(n-1) + f(n) % ()   
//f(n-1) << (log2(n)) + n


//11110000011011100


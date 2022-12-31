// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(int n) {
        return helper(n) - 1;
    }
    uint64_t helper(uint64_t n)
    {
        if(n == 1) 
        {
            return 1;
        }
        if(n % 2 == 0)
        {
            return 1 + helper(n / 2);
        }else{
      
            return 1 + std::min(helper(n + 1), helper(n - 1));
        }
    }
};
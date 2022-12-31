// https://leetcode.com/problems/ugly-number

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        std::vector<int> primes {2, 3, 5};
        int idx = 0;
        while(n > 1)
        {
            if(n % primes[idx] == 0)
            {
                n /= primes[idx];
            }else idx++;
            if(n == 1) return true;
            if(idx >= primes.size())
            {
                return false;
            }
        }
        return true;
    }
};
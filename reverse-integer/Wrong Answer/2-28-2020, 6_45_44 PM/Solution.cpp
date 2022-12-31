// https://leetcode.com/problems/reverse-integer

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int reverse(int x){
    std::vector<int> digits;
    int k = abs(x);
    while (k > 0)
    {
        digits.push_back(k % 10);
        k /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    int res = 0;
    int p = 0;
    for(auto &digit : digits){
        res += pow(10, p++) * digit;
    }
    if (x > 0) return res;
    return -res;
    
}
};
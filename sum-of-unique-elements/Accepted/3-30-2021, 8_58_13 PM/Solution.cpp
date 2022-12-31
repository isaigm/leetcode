// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int tab[101] = {0};
        int sum = 0;
        for(const auto &x: nums)
        {
            tab[x]++;
        }
        for(const auto &x: nums)
        {
            if(tab[x] == 1) sum += x;
        }
        return sum;
    }
};
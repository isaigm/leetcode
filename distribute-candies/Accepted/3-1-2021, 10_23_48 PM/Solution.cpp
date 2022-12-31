// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::set<int> s;
        int n = candyType.size();
        for(const auto &c: candyType)
        {
            s.insert(c);
        }
        int size = s.size();
        if(n / 2 >= size)
        {
            return size;
        }else
        {
            return n / 2;
        }
    }
};
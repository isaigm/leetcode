// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int frq[501] = {0};
        int lucky = -1;
        for(const auto &x: arr)
        {
            frq[x]++;
        }
        for(int i = 1; i < 501; i++)
        {
            if(frq[i] == i)
            {
                lucky = std::max(lucky, i);
            }
        }
        return lucky;
    }
};
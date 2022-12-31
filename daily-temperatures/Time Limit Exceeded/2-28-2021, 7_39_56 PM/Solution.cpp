// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> ans(T.size());
        for(int i = 0; i < T.size() - 1; i++)
        {
            int m = 0;
            for(int j = i + 1; j < T.size(); j++)
            {
                if(T[j]  > T[i])
                {
                    m = j - i;
                    break;
                }
            }
            ans[i] = m;
        }
        ans[T.size() - 1] = 0;
        return ans;
    }
};
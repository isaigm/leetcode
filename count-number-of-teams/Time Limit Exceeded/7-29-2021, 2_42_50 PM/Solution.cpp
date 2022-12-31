// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    std::vector<int> arr{rating[i], rating[j], rating[k]};
                    bool f1 = true;
                    bool f2 = true;
                    for(int h = 0; h < 2; h++)
                    {
                        f1 = f1 && (arr[h] < arr[h + 1]);
                        f2 = f2 && (arr[h] > arr[h + 1]);
                    }
                    ans += f1 + f2;
                }
            }
        }
        return ans;
    }
};
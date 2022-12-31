// https://leetcode.com/problems/count-all-possible-routes

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        std::map<std::pair<int, int>, uint64_t> dp;
        return util(dp, locations, start, finish, fuel) % 1000000007;
    }
    uint64_t util(std::map<std::pair<int, int>, uint64_t> &dp, std::vector<int> &locations, int curr, int finish, int fuel)
    {
        if(dp.find({curr, fuel}) != dp.end())
        {
            return dp[{curr, fuel}];
        }
        uint64_t ans = 0;
        if(fuel < 0)
        {
            return 0;
        }
        if(curr == finish)
        {
            ans =  1;
        }
        for(int i = 0; i < locations.size(); i++)
        {
            if(i != curr)
            {
                int f = fuel - std::abs(locations[i] - locations[curr]);
               
                ans += util(dp, locations, i, finish, f) % 1000000007;
            }
        }
        dp[{curr, fuel}] = ans;
        return ans;
    }
};
// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::vector<int> ans;
        for(const auto &circle: queries)
        {
            int x = circle[0];
            int y = circle[1];
            int r = circle[2];
            int p = 0;
            for(const auto &point: points)
            {
                
                int xp = point[0];
                int yp = point[1];
                double distance = std::sqrt(std::pow(xp - x, 2) + std::pow(yp - y, 2));
                
                if(distance <= double(r))
                {
                    p++;
                }
                
            }
            ans.push_back(p);
            
        }
        return ans;
    }
};
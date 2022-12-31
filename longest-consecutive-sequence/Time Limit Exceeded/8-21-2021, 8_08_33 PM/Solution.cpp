// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        std::set<int> numss;
        std::set<int> visited;
        int ans = 1;
        for(const auto &x: nums)
        {
            numss.insert(x);
        }
        for(auto x: nums)
        {
            int temp = x;
            int curr_len = 1;
            if(visited.find(x) != visited.end()) continue;
            while(numss.find(x + 1) != numss.end() )
            {
                visited.insert(x);
                x++;
                curr_len++;
            }
            visited.insert(temp);
            ans = std::max(ans, curr_len);
        }
        return ans;
       
    }
};
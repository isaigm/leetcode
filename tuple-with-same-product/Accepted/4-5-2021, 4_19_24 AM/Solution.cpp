// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::unordered_map<int, int> frq;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                frq[nums[i] * nums[j]]++;
            }
        }
        for(const auto [product, times]: frq)
        {
            if(times > 1)
            {
                ans += 8 * (times - 1) * times / 2;
            }
        }
        return ans;
    }
};
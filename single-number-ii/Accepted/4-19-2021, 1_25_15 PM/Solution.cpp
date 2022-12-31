// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
    std::map<int, int> counting;
    for(const auto &it: nums){
        counting[it]++;
    }
    for(const auto &p: counting){
        if(p.second == 1){
            ans = p.first;
            break;
        }
    }
    return ans; 
    }
};
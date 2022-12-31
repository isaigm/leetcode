// https://leetcode.com/problems/single-number-iii

class Solution {
public:
   std::vector<int> singleNumber(std::vector<int>& nums) {
    std::vector<int> res;
    std::map<int, int> counting;
    for(const auto &it: nums){
        counting[it]++;
    }
    for(const auto &p: counting){
        if(p.second == 1){
            res.push_back(p.first);
        }
    }
    return res;
}
};
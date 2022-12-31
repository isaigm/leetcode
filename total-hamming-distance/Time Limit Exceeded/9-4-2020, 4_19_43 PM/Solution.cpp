// https://leetcode.com/problems/total-hamming-distance

class Solution {
public:
   int hammingDistance(int i1, int i2){
    return __builtin_popcount(i1 ^ i2);
}
int totalHammingDistance(std::vector<int>& nums) {
    int total = 0;
    for(size_t i = 0; i < nums.size(); i++){
        for(size_t j = i + 1; j < nums.size(); j++){
            total += hammingDistance(nums[i], nums[j]);
        }
    }
    return total;
}
};
// https://leetcode.com/problems/total-hamming-distance

class Solution {
public:
   int hammingDistance(int i1, int i2){
    int count = 0;
    while (i1 > 0 || i2 > 0) {
        int b1 = i1 & 0x1;
        int b2 = i2 & 0x1;
        i1 >>= 1;
        i2 >>= 1;
        if(b1 != b2) count++;
    }
    return count;
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
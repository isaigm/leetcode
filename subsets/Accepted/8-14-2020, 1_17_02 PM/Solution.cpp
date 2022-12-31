// https://leetcode.com/problems/subsets

class Solution {
public:
  void helper(std::vector<std::vector<int>> &res, std::vector<int> &nums, std::vector<int> &curr, size_t n, size_t max_len, size_t start, size_t left){
    if(curr.size() == max_len){
        res.push_back(curr);
        return;
    }
    for(auto i = start; i <= nums.size() - left; i++){
        curr.push_back(nums[i]);
        helper(res, nums, curr, n, max_len, i + 1, left - 1);
        curr.pop_back();
    }
}
std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    res.push_back({});
    for(int i = 1; i <= nums.size(); i++){
        std::vector<int> curr;
        helper(res, nums, curr, nums.size(), i, 0, i);
    }
    return res;
}

};
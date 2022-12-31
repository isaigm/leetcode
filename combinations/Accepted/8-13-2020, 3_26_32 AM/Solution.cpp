// https://leetcode.com/problems/combinations

class Solution {
public:
  void combinations(std::vector<std::vector<int>> &res, std::vector<int> curr, size_t n, size_t max_len, size_t start){
    if(curr.size() == max_len){
        res.push_back(curr);
        return;
    }
    for(auto i = start; i <= n; i++){
        curr.push_back(i);
        combinations(res, curr, n, max_len, i + 1);
        curr.pop_back();
    }
}
std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> curr;
    combinations(res, curr, n, k, 1);
    return res;
}
};
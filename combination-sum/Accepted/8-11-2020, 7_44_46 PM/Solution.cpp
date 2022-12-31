// https://leetcode.com/problems/combination-sum

class Solution {
public:
void dfs(std::vector<std::vector<int>> &sums, std::vector<int>&candidates, std::vector<int> &combination, int curr_idx, int target){
    if(target == 0){
        sums.push_back(combination);
        return;
    }
    for(int i = curr_idx; i < (int) candidates.size(); i++){
        if(candidates[i] > target) break;
        combination.push_back(candidates[i]);
        dfs(sums, candidates, combination, i, target - candidates[i]);
        combination.pop_back();
    }
}
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> sums;
    std::vector<int> aux;
    std::sort(candidates.begin(), candidates.end());
    dfs(sums, candidates, aux, 0, target);
    return sums;
}

};
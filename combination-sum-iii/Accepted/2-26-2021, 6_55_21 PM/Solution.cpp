// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    void util(std::vector<std::vector<int>> &ans, std::vector<int> &curr, int k, int n, int idx){
        if(n == 0 && curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i  <= 9; i++){
            if(i > n)
            {
                continue;
            }
            curr.push_back(i);
            util(ans, curr, k, n - i, i + 1);
            curr.pop_back();
        }     
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        util(ans, curr, k, n, 1);
        return ans;
    }
};
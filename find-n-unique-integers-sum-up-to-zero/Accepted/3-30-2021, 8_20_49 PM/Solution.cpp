// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        std::vector<int> ans;
        int sum = 0;
        for(int i = 1; i <= n - 1; i++)
        {
            ans.push_back(i);
            sum += i;
        }
        ans.push_back(-sum);
        return ans;
    }
};
// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    void backtracking(std::vector<std::string> &ans, std::string &s, int idx)
    {
        ans.push_back(s);
        for(int i = idx; i < s.size(); i++)
        {
            if(!std::isdigit(s[i]))
            {
                if(std::isupper(s[i]))
                {
                    s[i] = std::tolower(s[i]);
                    backtracking(ans, s, i + 1);
                    s[i] = std::toupper(s[i]);
                }else{
                    s[i] = std::toupper(s[i]);
                    backtracking(ans, s, i + 1);
                    s[i] = std::tolower(s[i]);
                }
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        std::vector<std::string> ans;
        backtracking(ans, S, 0);
        return ans;
    }
};
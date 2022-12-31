// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string s;
        helper(res, s, n, 0, 0);
        
        
        return res;
    }
    bool is_ok(std::string &s)
    {
        int c = 0;
        for(const auto &x: s)
        {
            if(x == '(')
            {
                c++;
            }
            if(x == ')')
            {
                c--;
            }
            if(c < 0) return false;
        }
        return c == 0;
    }
    void helper(std::vector<std::string> &ans, std::string &s, int n, int left, int right)
    {
        if(s.size() == 2 * n)
        {
            if(is_ok(s))
            {
               ans.push_back(s);
            }
            return;
        }
        if(left < n)
        {
            s.push_back('(');
            helper(ans, s, n, left + 1, right);
            s.pop_back();
        }
        if(right < n)
        {
            s.push_back(')');
            helper(ans, s, n, left, right + 1);
            s.pop_back();
        }
       
        
    }
};
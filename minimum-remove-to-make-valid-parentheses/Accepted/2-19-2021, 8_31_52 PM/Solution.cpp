// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

struct DefaultValue
{
    int i = -1;
};
class Solution {
public:
    int find_closing_bracket(std::string &s, std::map<int, int> &brackets, int idx)
    {
        int depth = 1;
        for(int i = idx + 1; i < s.size(); i++)
        {
            switch (s[i])
            {
                case '(':
                    depth++;
                    break;
                case ')':
                   
                    if(--depth == 0)
                    {
                        return i;
                    }
                    break;
                default:
                    break;
            }
        }
        return -1;
    }
    string minRemoveToMakeValid(string s) {
        std::map<int, int> brackets;
        std::map<int, DefaultValue> inv;
        std::string ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                brackets[i] = find_closing_bracket(s, brackets, i);
                if(brackets[i] >= 0)
                {
                    inv[brackets[i]] = {i};
                }
            }
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                if(brackets[i] >= 0)
                {
                    ans.push_back('(');
                }
            }else if(s[i] == ')')
            {
                auto idx = inv[i].i;
                if(idx >= 0)
                {
                    ans.push_back(')');
                }
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};
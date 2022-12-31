// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int find_closing_bracket(std::string &s, int idx)
    {
        int depth = 1;
        for(int i = idx + 1; i < s.size(); i++){
            switch(s[i]){
                case '(':
                    depth++;
                    break;
                case ')':
                    if(--depth == 0) return i;
                    break;
            }
        }
        return -1;
    }
    int util(std::map<int, int> &brackets, std::string &s, int start, int end)
    {
        int res = 0;
        for(int i = start; i < end; i++){
            if(brackets[i] == i + 1){
                res++;
            }else if(s[i] == '('){
                res += 2 * util(brackets, s, i + 1, brackets[i]);
                i = brackets[i];
            }
        }
        return res;
    }
    int scoreOfParentheses(string S) {
        std::map<int, int> brackets;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '('){
                brackets[i] = find_closing_bracket(S, i);
            }
        }
        return util(brackets, S, 0, S.size() - 1);
    }
};
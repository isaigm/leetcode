// https://leetcode.com/problems/decode-string

class Solution {
public:
 int find_closing_bracket(const std::string &s, int pos)
{
    int depth = 1;
    for (int i = pos + 1; i < int(s.length()); i++)
    {
        switch (s[i])
        {
        case '[':
            depth++;
            break;
        case ']':
            if (--depth == 0)
            {
                return i;
            }
            break;
        }
    }
    return -1;
}

std::string repeat(std::string &&s, int n)
{
    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << s;
    return os.str();
}

std::string helper(std::map<int, int> &brackets, std::string &s,
                   size_t &start)
{
    std::string temp = "";
    size_t end = brackets[start];
    for (size_t j = start; j < end; j++)
    {
        if (isdigit(s[j]))
        {
            std::string k;
            while (isdigit(s[j]))
            {
                k.push_back(s[j]);
                j++;
            }
            std::stringstream st(k);
            int times;
            st >> times;
            start = j;
            temp += repeat(helper(brackets, s, start), times);
            j = start - 1;
        }
        if (s[j] != ']' && s[j] != '[' && !isdigit(s[j]))
        {
            temp.push_back(s[j]);
        }
    }
    start = end + 1;
    return temp;
}



    string decodeString(string s) {
         std::map<int, int> brackets;
        for (size_t j = 0; j < s.size(); j++)
    {
        if (s[j] == '[')
        {
            brackets[j] = find_closing_bracket(s, j);
        }
    }
        size_t i = 0;
        brackets[0] = s.size();
    auto t = helper(brackets, s, i);
        return t;
    }
};
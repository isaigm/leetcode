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

std::string repeat(std::string &s, int n)
{
    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << s;
    return os.str();
}

std::string helper(std::map<int, int> &brackets, std::string &s,
                   size_t &i)
{
    std::string temp = "";
    std::string h = "";
    while (i < s.size())
    {
        
        std::string k;
        if(!isdigit(s[i]) && s[i] != ']'){
            h.push_back(s[i]);
        }
        while (isdigit(s[i]))
        {
            k.push_back(s[i]);
            i++;
        }
        if (k.size() > 0)
        {
            std::stringstream st(k);
            int times;
            st >> times;
            size_t start = i + 1;
            size_t end = brackets[i];
            for (size_t j = start; j < end; j++)
            {
                if (isdigit(s[j]))
                {
                    i = j;
                    temp += helper(brackets, s, i);
                    j = i;
                }
                else if (s[j] == '[')
                {
                    i = j + 1;
                    temp += helper(brackets, s, i);
                    j = i;
                }
                else if(s[j] != ']')
                {
                    temp.push_back(s[j]);
                }
            }
            i = end;
            h += repeat(temp, times);
            temp = "";
        }
        i++;
    }
    return h;
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
    auto t = helper(brackets, s, i);
        return t;
    }
};
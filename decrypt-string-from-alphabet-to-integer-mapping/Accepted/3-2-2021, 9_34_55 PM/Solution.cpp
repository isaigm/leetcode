// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping

class Solution {
public:
    string freqAlphabets(string s) {
        std::map<std::string, char> m;
        std::string ans;
        for(int i = 0; i < 9; i++)
        {
            std::string str = "0";
            str[0] = i + 1 + '0';
            m[str] = 'a' + i;
        }
        for(int i = 0; i < 'z' - 'j' + 1; i++)
        {
            std::stringstream ss;  
            ss << (i + 10);
            std::string str;
            ss >> str;
            str += "#";
            m[str] = 'j' + i;
        }
        for(int idx = 0; idx < s.size(); idx++)
        {
            if(idx + 2 < s.size() && s[idx + 2] == '#')
            {
                auto ss = s.substr(idx, 3);
                ans += m[ss];
                idx += 2;
            }else{
                ans += m[s.substr(idx, 1)];
            }
        }
        return ans;
        
    }
};

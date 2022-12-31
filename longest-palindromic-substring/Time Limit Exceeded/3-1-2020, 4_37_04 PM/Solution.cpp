// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
   std::string longestPalindrome(std::string s) {
    if (s.length() > 1){
        std::vector<std::string> substrs;
        for (size_t i = 0; i < s.length(); i++)
        {
            for (size_t j = i; j < s.length(); j++)
            {
                std::string str = s.substr(i, j - i + 1);
                std::string cpy = str;
                std::reverse(str.begin(), str.end());
                if (!str.compare(cpy))
                {
                    substrs.push_back(str);
                }
            }
        }
         auto iter = std::max_element(substrs.begin(), substrs.end(), [](std::string &str1, std::string &str2) {
            return str1.length() < str2.length();
        });
        return *iter;
    }else return s;
}
};
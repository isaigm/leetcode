// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string text) {
        std::istringstream iss(text);
        std::map<char, std::string> cs;
        std::map<std::string, bool> sb;
        std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                         std::istream_iterator<std::string>());
       
        for (size_t t = 0; t < pattern.size(); t++)
        {
            if(cs.find(pattern[t]) == cs.end()){
                if (!sb[results[t]])
                {
                    cs[pattern[t]] = results[t];
                    sb[results[t]] = true;
                }else return false;
            }else if(cs[pattern[t]] != results[t]) return false;
        }
        return true;
    }
};
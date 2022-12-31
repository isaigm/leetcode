// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
   std::string longestCommonPrefix(std::vector<std::string> &strs) {
    auto common = [](std::string &str1, std::string &str2){
        std::string res = "";
        size_t i = 0;
        size_t j = 0;
        while ((i < str1.length() && j < str2.length()) && str1[i] == str2[j])
        {
            res.push_back(str1[i]);
            i++;
            j++;
        }
        return res;
    };
    auto res = common(strs[0], strs[1]);
    if(!res.length()) return res;
    for (size_t i = 1; i < strs.size() - 1; i++)
    {
        auto aux = common(strs[i], strs[i+1]);
        auto cmp = aux.compare(res);
        if(cmp != 0) return std::string("");
        res = aux;
    }
    return res;    
}
};
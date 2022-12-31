// https://leetcode.com/problems/group-anagrams

class Solution {
public:
   std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::map<std::string, std::vector<std::string>> anagrams;
    std::vector<std::vector<std::string>> res;
    for(auto &str: strs){
        std::string aux = str;
        std::sort(aux.begin(), aux.end());
        anagrams[aux].push_back(str);
    }
    for(auto &it: anagrams){
        res.push_back(it.second);
    }
    return res;
}
};
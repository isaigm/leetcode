// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
   std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> ans;
    std::map<std::string, int> cnt;
    std::string substr;
    if (s.size() < 10) return ans;
    for (int i = 0; i < 10; i++)
    {
        substr.push_back(s[i]);
    }
    cnt[substr]++;
    for (int i = 10; i < s.size(); i++)
    {
        substr.push_back(s[i]);
        substr.erase(substr.begin());
        cnt[substr]++;
    }
    for (auto& e : cnt)
    {
        if (e.second > 1) ans.push_back(e.first);
    }
    return ans;

}
};
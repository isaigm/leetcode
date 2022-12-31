// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
bool matches(std::string &word, std::string& pattern)
{
    if (pattern.size() != word.size()) return false;
    char word2pattern[26] = {0};
    char pattern2word[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        pattern2word[i] = 0;
        word2pattern[i] = 0;
    }
  
    for (int i = 0; i < pattern.size(); i++)
    {
        int wordidx = word[i] - 'a';
        int patternidx = pattern[i] - 'a';
        if (word2pattern[wordidx] == 0 && pattern2word[patternidx] == 0)
        {
            word2pattern[wordidx] = pattern[i];
            pattern2word[patternidx] = word[i];
        }
        else if (word2pattern[wordidx] == 0 && pattern2word[patternidx] != 0) return false;
        else if (word2pattern[wordidx] != 0 && word2pattern[wordidx] != pattern[i]) return false;
        else if (word2pattern[wordidx] != 0 && pattern2word[patternidx] != 0 && !(pattern2word[patternidx] == word[i] && word2pattern[wordidx] == pattern[i])) return false;


        
    }
    return true;
}
std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
    std::vector<std::string> res;
    for (auto& w : words)
    {
        if (matches(w, pattern)) res.push_back(w);
    }
    return res;
}
};

    
    

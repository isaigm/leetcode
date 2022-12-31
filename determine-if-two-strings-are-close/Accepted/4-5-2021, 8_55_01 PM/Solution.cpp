// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int frq1[26] = {0};
        int frq2[26] = {0};
        for(int i = 0; i < word1.size(); i++)
        {
            frq1[word1[i] - 'a']++;
            frq2[word2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(frq1[i] == 0 && frq2[i] == 0) continue;
            if((frq1[i] == 0 && frq2[i] > 0) || (frq2[i] == 0 && frq1[i] > 0))  
            {
                return false;
            }
        }
        std::sort(std::begin(frq1), std::end(frq1));
        std::sort(std::begin(frq2), std::end(frq2));
        for(int i = 0; i < 26; i++)
        {
            if(frq1[i] != frq2[i]) return false;
        }
        return true;
    }
};
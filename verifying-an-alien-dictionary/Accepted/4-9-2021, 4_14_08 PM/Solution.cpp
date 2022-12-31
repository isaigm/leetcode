// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int ord[26];
        for(int i = 0; i < 26; i++)
        {
            ord[order[i] - 'a'] = i;
        }
        auto are_sorted = [&ord](std::string &s1, std::string &s2)
        {
            int i = 0;
            int j = 0;
            while(i < s1.size() && j < s2.size())
            {

                if(ord[s1[i] - 'a'] > ord[s2[j] - 'a'])
                {
                    return false;
                }
                if(ord[s1[i] - 'a'] < ord[s2[j] - 'a'])
                {
                    return true;
                }
                i++;
                j++;
            }
            if(j == s2.size() && j < s1.size()) return false;
            return true;
            
        };
        for(int i = 0; i < words.size() - 1; i++)
        {
            if(!are_sorted(words[i], words[i + 1])) return false;
        }
        return true;
    }
};
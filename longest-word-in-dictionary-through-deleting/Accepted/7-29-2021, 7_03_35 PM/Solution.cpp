// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        std::vector<std::string> valid_words;
        for(const auto &w: dictionary)
        {
            if(s.size() >= w.size())
            {
                int j = 0;
                bool flag = false;
                for(int i = 0; i < s.size(); i++)
                {
                    if(s[i] == w[j])
                    {
                        j++;
                    }
                    if(j >= w.size()){
                        flag = true;
                        break;
                    }
                }
                if(flag)
                {
                    valid_words.push_back(w);
                }
            }
        }
        
        if(valid_words.size() == 0)
        {
            return "";
        }
        std::sort(valid_words.begin(), valid_words.end(), [](std::string &s1, std::string &s2){  
            if(s1.size() == s2.size()) return s1 < s2;
            return s1.size() > s2.size();
        });
        
        
        return valid_words[0];
    }
};
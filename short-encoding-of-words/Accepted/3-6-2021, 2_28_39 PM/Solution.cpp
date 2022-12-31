// https://leetcode.com/problems/short-encoding-of-words

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        std::sort(words.begin(), words.end(), [](const auto &s1, const auto &s2){
           return s1.size() > s2.size(); 
        });
        std::map<std::string, bool> m;
        auto check_is_last_substr = [](std::string &s1, std::string &s2)
        {
            int i = s2.size() - 1;
            int j = s1.size() - 1;
            while(i >= 0)
            {
                if(s2[i] != s1[j])
                {
                    return false;
                }
                i--;
                j--;
            }
            return true;
        };
        for(int i = 0; i < words.size(); i++)
        {
            if(m.find(words[i]) == m.end())
            {
                for(int j = i +  1; j < words.size(); j++)
                {
                    if(check_is_last_substr(words[i], words[j]))
                    {
                        m[words[j]] = true;
                    }
                }
                m[words[i]] = true;
                ans += words[i].size() + 1;
            }
        }
        return ans;
    }
};
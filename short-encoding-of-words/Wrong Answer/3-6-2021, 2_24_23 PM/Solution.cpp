// https://leetcode.com/problems/short-encoding-of-words

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        std::sort(words.begin(), words.end(), [](const auto &s1, const auto &s2){
           return s1.size() > s2.size(); 
        });
        std::map<std::string, bool> m;
        for(int i = 0; i < words.size(); i++)
        {
            if(m.find(words[i]) == m.end())
            {
                for(int j = i +  1; j < words.size(); j++)
                {
                    int pos = words[i].find(words[j]);
                    if(pos != std::string::npos && pos + words[j].size() == words[i].size())
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
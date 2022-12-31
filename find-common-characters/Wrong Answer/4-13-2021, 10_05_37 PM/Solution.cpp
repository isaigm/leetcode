// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        std::vector<std::string> ans;
        for(int i = 0; i < 26; i++)
        {
            auto ch = 'a' + i;
            std::set<int> se;
            int times = 0;
            for(auto &s: A)
            {
                times = std::count(s.begin(), s.end(), ch);
                se.insert(times);
            }
            if(se.size() == 1 && times > 0)
            {
                std::string s = " ";
                s[0] = ch;
                for(int i = 0; i < times; i++)
                {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
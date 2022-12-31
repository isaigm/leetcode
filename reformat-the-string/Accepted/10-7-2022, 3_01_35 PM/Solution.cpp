// https://leetcode.com/problems/reformat-the-string

class Solution {
public:
    string reformat(string s) {
        int letters = 0;
        int digits = 0;
        std::string d;
        std::string l;
        for(auto &ch: s)
        {
            if(std::isdigit(ch)) {
                digits++;
                d += ch;
            }
            else {
                letters++;
                l += ch;
            }
        }
        if(std::abs(digits - letters) <= 1)
        {
            std::string res;
            int li = 0;
            int di = 0;
            bool who = true;
            if(digits > letters) who = false;
            int pr = 0;
            while(true){
                if(who)
                {
                    res += l[li];
                    li++;
                }else{
                    res += d[di];
                    di++;
                }
                pr++;
                if(pr >= s.size()) break;
                who = !who;
            }
            return res;
        }
        return "";
    }
};

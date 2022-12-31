// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        std::vector<int> aux;
        int zeroes = 0;
        int ones = 0;
        int total = 0;
        bool last = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
            {
                if(i - 1 >= 0 && s[i - 1] == '1') 
                {
                    aux.push_back(ones);
                    ones = 0;
                }
                zeroes++;
                last = false;
            }
            if(s[i] == '1')
            { 
                if(i - 1 >= 0 && s[i - 1] == '0')
                {
                    aux.push_back(zeroes);
                    zeroes = 0;
                }
                last = true;
                ones++;
            }
        }
        if(last) aux.push_back(ones);
        else aux.push_back(zeroes);
        for(int i = 1; i < aux.size(); i++)
        {
            total += std::min(aux[i], aux[i - 1]);
        }
        return total;
    }
};
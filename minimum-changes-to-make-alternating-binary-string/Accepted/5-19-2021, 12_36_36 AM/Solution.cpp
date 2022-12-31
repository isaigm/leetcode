// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        char c = '0';
        char c2 = '1';
        int hd1 = 0, hd2 = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(c2 != s[i]){
                hd2++;
            }
            if(c != s[i])
            {
                hd1++;
            }
            c = !(c - '0') + '0';
            c2 = !(c2 - '0') + '0';
        }
        std::cout << hd1 << "\n";
        std::cout << hd2 << "\n";
        return std::min(hd1, hd2);
    }
};
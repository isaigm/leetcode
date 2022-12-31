// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
  int romanToInt(std::string s){
    int res = 0;
    std::map<char, int> values {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
                                {'D', 500}, {'M', 1000}};
    auto len = s.size();
    for(size_t i = 0; i < len; i++){
        char r = s[i];
        bool flag = false;
        if(r == 'I' && i + 1 < len){
            switch (s[i + 1]) {
            case 'V':
                res += 4;
                i++;
                flag = true;
                break;
            case 'X':
                res += 9;
                i++;
                flag = true;
                break;
            default:
                break;
            }
        }
        if(r == 'X' && i + 1 < len){
            switch (s[i + 1]) {
            case 'L':
                res += 40;
                i++;
                flag = true;
                break;
            case 'C':
                res += 90;
                i++;
                flag = true;
                break;
            default:
                break;
            }
        }
        if(r == 'C' && i + 1 < len){
            switch (s[i + 1]) {
            case 'D':
                res += 400;
                i++;
                flag = true;
                break;
            case 'M':
                res += 900;
                i++;
                flag = true;
                break;
            default:
                break;
            }
        }
        if(!flag){
            res += values[r];
        }
    }
    return res;
}
};
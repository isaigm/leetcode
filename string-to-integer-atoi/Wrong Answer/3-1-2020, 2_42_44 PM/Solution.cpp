// https://leetcode.com/problems/string-to-integer-atoi

__int128_t pow(__int128_t x, __int128_t y){
    __int128_t res = 1;
    for (__int128_t i = 1; i <= y; i++)
    {
        res *= x;
    }
    return res;
    
}
class Solution {
public:
int myAtoi(std::string str) {
        size_t index = 0;
        size_t len = str.length();
        int64_t sign = 0;
        while(str[index] == ' ' && index++ < len){}
        if(index >= len) return 0;
        if(str[index] == '-'){
            sign = -1;
            index++;
        }else if(str[index] == '+'){
            sign = 1;
            index++;
        }else if(isdigit(str[index])){
            sign = 1;
        }else return 0;
        if(index >= len) return 0;
        size_t i = index;
        int digits = 0;
        __int128_t res = 0;
        while (isdigit(str[i++])){ digits++; }
        while (isdigit(str[index]))
        {
            res += pow(10, --digits) * (str[index] - '0');
            if (res * sign < INT32_MIN) return INT32_MIN;
            else if (res * sign > INT32_MAX) return INT32_MAX;
            index++;
        }
        return res * sign;
                
}
};
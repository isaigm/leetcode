// https://leetcode.com/problems/string-to-integer-atoi

int64_t pow(int64_t x, int64_t y){
    int64_t res = 1;
    for (int64_t i = 1; i <= y; i++)
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
        int sign = 0;
        while(str[index] == ' ' && index++ < len){}
        if(index >= str.length()) return 0;
        if(str[index] == '-'){
            sign = -1;
            index++;
        }else if(str[index] == '+'){
            sign = 1;
            index++;
        }else if(isdigit(str[index])){
            sign = 1;
        }else return 0;
        if(index >= str.length()) return 0;
        size_t i = index;
        int digits = 0;
        int64_t res = 0;
        while (isdigit(str[i++])){ digits++; }
        while (isdigit(str[index]))
        {
            res += pow(10, --digits) * (str[index] - '0');
            index++;
        }
        res *= sign;
        if (res < -INT32_MAX) return -INT32_MAX-1;
        else if (res > INT32_MAX) return INT32_MAX;
        return res;
                
}
};
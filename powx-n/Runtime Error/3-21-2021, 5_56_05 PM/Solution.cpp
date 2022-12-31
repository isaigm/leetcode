// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        else if(n < 0) return 1 / poww(x, -n);
        return poww(x, n);
    }
    double poww(double x, int n)
    {
         if(n == 1){
            return x;
        }else if(n % 2 == 0){
            double temp = poww(x, n / 2);
            return temp * temp;
        }
        else return x * poww(x, n - 1);
    }
};
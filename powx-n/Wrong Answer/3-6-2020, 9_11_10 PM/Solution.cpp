// https://leetcode.com/problems/powx-n

class Solution {
public:
   double aux(double x, int n){
    double res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= x;
    }
    return res;
    
}
double myPow(double x, int n) {
    if (n == 1) return x;
    else if (n % 2 == 0) {
        double temp = aux(x, n / 2);
        return temp * temp;
    }else return x * myPow(x, n - 1);
}
};
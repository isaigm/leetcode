// https://leetcode.com/problems/climbing-stairs

int climbStairs(int n){
    int a = 0, b = 1, k = 0;
    for(int i = 0; i < n; i++){
        k = a + b;
        a = b;
        b = k;
    }
    return k;
}
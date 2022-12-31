// https://leetcode.com/problems/total-hamming-distance

typedef long long int lli;
const int m = 1e9 + 7;
class Solution {
public:
 lli add(lli a, lli b){
      return ((a % m) + (b % m));
   }
   lli mul(lli a, lli b){
      return ((a % m) * (b % m));
   }
   int cntBits(vector<int>& a){
      vector<vector<lli> > bits(32, vector<lli>(2));
      lli ans = 0;
      int n = a.size();
      for (int i = 0; i < n; i++) {
         lli x = a[i];
         for (lli j = 0; j < 32; j++) {
            lli b = (x >> j) & 1;
            ans = add(ans, mul((lli)1, bits[j][!b]));
            bits[j][b] = add(bits[j][b], (lli)1);
         }
      }
      return ans;
   }
   int totalHammingDistance(vector<int>& nums){
      return cntBits(nums);
   }
};
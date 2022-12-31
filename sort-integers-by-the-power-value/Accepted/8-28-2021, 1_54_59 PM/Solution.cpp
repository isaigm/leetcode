// https://leetcode.com/problems/sort-integers-by-the-power-value

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        std::map<int, int> dp;
        std::vector<std::pair<int, int>> aux;
        for(int i = lo; i <= hi; i++)
        {
            aux.push_back({i, steps(dp, i)}); 
        }
        
        std::sort(aux.begin(), aux.end(), [](auto &p1, auto &p2){
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });
   
        return aux[k - 1].first;
    }
    int steps(std::map<int, int> &dp, int n )
    {
        if(n == 1) return 0;
        if(dp.find(n) != dp.end())
        {
            return dp[n];
        }
        
        int res = 0;
        if(n % 2 == 0)
        {
            res = 1 + steps(dp, n / 2);
        }else
        {
            res = 1 + steps(dp, 3 * n + 1);
        }
        dp[n] = res;
       
        return res;
    }
};
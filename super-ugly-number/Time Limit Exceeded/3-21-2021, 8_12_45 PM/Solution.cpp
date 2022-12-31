// https://leetcode.com/problems/super-ugly-number

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        bool pprimes[1001];
        std::vector<int> all_primes_to_1000;
        std::set<int> what_primes;
        for(const auto &p: primes)
        {
            what_primes.insert(p);
        }
        for(int i = 2; i < 1001; i++)
        {
            pprimes[i] = true;
        }
        for(int i = 2; i < 1001; i++)
        {
            for(int j = 2; i * j < 1001; j++)
            {
                pprimes[i * j] = false;
            }
        }
        for(int i = 2; i < 1001; i++)
        {
            if(pprimes[i])
            {
                all_primes_to_1000.push_back(i);
            }
        }
        auto fact = [&](int s)
        {
            int idx = 0;
            while(s > 1 && idx < all_primes_to_1000.size())
            {
                if(s % all_primes_to_1000[idx] == 0)
                {
                    if(what_primes.find(all_primes_to_1000[idx]) == what_primes.end())
                        return false;
                    s /= all_primes_to_1000[idx];
                }else idx++;
            }
            return s == 1;
        };
        int k = 0;
        int ans = 0;
        int p = 2;
        while(k < n - 1)
        {
            if(fact(p))
            {
                ans = p;
                k++; 
            }
            p++;
        }
        return ans;
    }
};

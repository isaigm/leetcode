// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        if(n == 4) return 4;
        if(n == 3) return 2;
        if(n == 2) return 1;
        if(n % 3 == 0) return std::pow(3, n / 3);
        std::vector<int> integers;
        int curr_sum = 0;
        int product = 1;
   
        while(curr_sum != n)
        {
            curr_sum += 3;
    
            integers.push_back(3);
            if(curr_sum > n)
            {
                int idx = integers.size() - 1;
                while(curr_sum != n)
                {
                    curr_sum -= 3;
                    
                    curr_sum += 2;
                    integers[idx] = 2;
                    idx--;
                }
                
                break;
            }
        }
        for(auto x: integers)
        {
            product *= x;
        }
        
        return product;
    }
};
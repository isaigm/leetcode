// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(n % 2)
            {
                  if(2*i < n)
                {
                    ans += 2*i;
                }else break; 
             
            }else
            {if(2*i + 1 < n)
                {
                    ans += 2*i + 1;
                }else break; 
            }
        }
        return ans; 
    }
};

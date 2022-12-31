// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

class Solution {
public:
    int count(std::vector<bool> &bits)
    {
        int cnt = 0;
        for(const auto &x: bits)
        {
            if(x) cnt++;
        }
        return cnt;
    }
    void shif_right(std::vector<bool> &bits)
    {
        for(int i = bits.size() - 1; i > 0; i--)
        {
            bits[i] = bits[i - 1];
        }
        bits[0] = 0;
    }
    void add_one(std::vector<bool> &bits)
    {
        int carry = 1;
        for(int i = bits.size() - 1; i > 0; i--)
        {
            if(carry)
            {
                if(bits[i] + carry > 1)
                {
                    bits[i] = 0;
                }else 
                {
                    bits[i] = 1;
                    carry = 0;
                    break;
                }
            }
        }
        if(carry)
        {
            bits[0] = 1;
        }
    }
    
    int numSteps(string s) {
        std::vector<bool> bits(s.size() + 1);
        s[0] = 0;
        for(int i = 0; i < s.size(); i++)
        {
            bits[i + 1] = s[i] - '0';
        }
        int steps = 0;
        int lsb = s.size();
      
        while(!(count(bits) == 1 && bits[lsb]))
        {
            if(bits[lsb])
            {
                add_one(bits);
            }else
            {
                shif_right(bits);
            }
            steps++;
        }
        return steps;
    }
};
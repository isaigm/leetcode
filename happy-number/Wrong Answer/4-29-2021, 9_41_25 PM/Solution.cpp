// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> seen;
        seen.insert(n);
        while(true)
        {
            n = get_squares_of_its_digits(n);
            if(seen.find(n) != seen.end()) return false;
            seen.insert(n);
            
            if(n == 1) return true;
        }
        return false;
    }
    int get_squares_of_its_digits(int k)
    {
        int s = 0;
        while(k > 0)
        {
            s += (k % 10) * (k % 10);
            k /= 10;
        }
        return s;
    }
};
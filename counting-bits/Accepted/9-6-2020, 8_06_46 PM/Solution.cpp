// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        auto bits = [](int k) -> int{
          int c = 0;
            while(k > 0){
                c += k & 1;
                k >>= 1;
            }
            return c;
        };    
        std::vector<int> res;
        for(int i = 0; i <= num; i++){
            res.push_back(bits(i));
        }
        return res;
    }
};

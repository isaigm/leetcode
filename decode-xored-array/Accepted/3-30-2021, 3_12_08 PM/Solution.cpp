// https://leetcode.com/problems/decode-xored-array

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        std::vector<int> decoded(encoded.size() + 1);
        decoded[0] = first;
        for(int i = 1; i < decoded.size(); i++)
        {
            decoded[i] = encoded[i - 1] xor decoded[i - 1];
        }
        
        return decoded;
    }
};

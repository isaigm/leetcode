// https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        std::set<int> s;
        for(int i = 0, j = 1; (j = j << 1) <= 1000000000; i++)
        {
            s.insert(hash(std::to_string(j)));
        }
        if(s.find(hash(std::to_string(N))) == s.end()) return false;
        return true;
    }
    long hash(string a) {
        long hashed = 0;
        for(int i = 0; i < a.length(); i++) {
            long t = a[i] * 16777619;
            hashed += t ^ (t >> 8);
        } 
        return hashed;
    }
};
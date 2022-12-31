// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 1) return 1;
        int e = 1;
        std::vector<int> freq;
        for(size_t idx = 0; idx + 1 < s.size(); idx++){
            if(s[idx] == s[idx + 1]){
                e++;
            }else{
                freq.push_back(e);
                e = 1;
            }
        }
        freq.push_back(e);
        return *std::max_element(freq.begin(), freq.end());
       
    }
};
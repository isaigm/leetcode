// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void helper(std::map<char, std::string> &mapping, std::vector<std::string> &res, std::string &curr, std::string &digits, size_t idx){
    if(curr.size() == digits.size()){
        res.push_back(curr);
        return;
    }
    if(idx < digits.length()){
        std::string aux = mapping[digits[idx]];
        for(size_t i = 0; i < aux.length(); i++){
            curr.push_back(aux[i]);
            helper(mapping, res, curr, digits, idx + 1);
            curr.pop_back();
        }
    }
}
std::vector<std::string> letterCombinations(std::string digits) {
    std::map<char, std::string> mapping {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                                        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    std::vector<std::string> res;
    std::string curr;
    helper(mapping, res, curr, digits, 0);
    return res;
}
};
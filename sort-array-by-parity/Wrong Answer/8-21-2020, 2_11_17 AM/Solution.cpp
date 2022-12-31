// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::sort(A.begin(), A.end(), [](int &n1, int &n2){
            if(n1 % 2 == 0) return false;
            if(n2 % 2 == 0 && n1 % 2 != 0) return true;
            return false;
        });
        return A;
    }
};
// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int g_inv = 0;
        int l_inv = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(i < A.size() - 1)
            {
                if(A[i] > A[i + 1]) l_inv++;
            }
            for(int j = i + 1; j < A.size(); j++)
            {
                if(A[i] > A[j]) g_inv++;
            }
        }
        return g_inv == l_inv;
    }
};
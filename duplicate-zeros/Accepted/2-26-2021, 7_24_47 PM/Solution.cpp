// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto get_zero = [&arr](int start)
        {
            for(int i = start; i < arr.size(); i++)
            {
                if(arr[i] == 0) return i;
            }
            return -1;
        };
        int start = 0;
        int idx;
        while((idx = get_zero(start)) != -1)
        {
            for(int i = arr.size() - 1; i > idx; i--)
            {
                arr[i] = arr[i - 1];
            }
            start = idx + 2;
        }
    }
};
// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        std::set<int> s;
        int ans;
        int missing_integers = 0;
        for(const auto &x: arr)
        {
            s.insert(x);
        }
        
        if(k < arr[0]) return k;
        missing_integers = arr[0] - 1;
        for(int i = arr[0]; i <= arr.back(); i++)
        {
            if(s.find(i) == s.end())
            {
                missing_integers++;
                if(missing_integers == k) return i;
            }
        }
        return arr.back() + (k - missing_integers);
      
    }
};
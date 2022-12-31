// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for(int i = 1; i < n - 1; i++)
        {
            int left_less = 0;
            int right_greater = 0;
            int left_greater = 0;
            int right_less = 0;
            
            for(int j = i - 1; j >= 0; j--)
            {
                if(rating[j] < rating[i]){
                    left_less++;
                }else{
                    left_greater++;
                }
            }
            for(int j = i + 1; j < n; j++)
            {
                if(rating[j] > rating[i]){
                    right_greater++;
                }else{
                    right_less++;
                }
            }
            ans += left_less * right_greater + right_less * left_greater;
        }
        return ans;
    }
};
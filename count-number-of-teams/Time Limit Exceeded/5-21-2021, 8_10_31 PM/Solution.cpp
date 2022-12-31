// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int s = 0;
        for(int i = 0; i < rating.size(); i++)
        {
            for(int j = i + 1; j < rating.size(); j++)
            {
                for(int k = j + 1; k  < rating.size(); k++)
                {
                    if(rating[i] < rating[j] && rating[j] < rating[k])
                    {
                        s++;
                    }else if(rating[i] > rating[j] && rating[j] > rating[k])
                    {
                        s++;
                    }
                }
            }
        }
        
        return s;
    }
};
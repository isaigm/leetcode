// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto &i1, const auto &i2){
           return i1[0] < i2[0]; 
        });
        int res = 0;
        int last = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[last][1]){
                res++;
                if(intervals[i][1] < intervals[last][1]){
                    last = 1;
                }
            }else last = i;
        }
        return res;
    }
};
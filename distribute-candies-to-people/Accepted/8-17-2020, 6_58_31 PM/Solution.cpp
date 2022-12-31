// https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
std::vector<int> distributeCandies(int candies, int num_people) {
        int i = 0;
        int p = 0;
        std::vector<int> res(num_people);
        while(candies > 0){
            int k = (i + 1) + num_people * p;
            if(candies - k >= 0){
                res[i] += k;
                candies -= k;
            }else{
                res[i] += candies;
                candies = 0;
            }
            i++;
            if(i >= num_people){
                i = 0;
                p++;
            }
        }
        return res;
}
};
// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        return back(nums, true, 0, 0) == 1;
        
    }
int back(std::vector<int> &nums, bool turn, int player1, int player2)
{
 
    if(nums.size() == 1)
    {
        if(turn)
        {
            if(player1 + nums[0] >= player2) return 1;
        }
        else if(player2 + nums[0] <= player1) return 1;

        return -1;
    }

    if(turn)
    {
        int temp = nums[0];

        nums.erase(nums.begin());
        int m1 = back(nums, false, player1 + temp, player2);
        
        nums.insert(nums.begin(), temp);
        temp = nums.back();
        nums.pop_back();
        
        
        int m2 = back(nums, false, player1 + temp, player2);
        nums.push_back(temp);

        return std::max(m1, m2);
    }else{
        int temp = nums[0];

        nums.erase(nums.begin());

        int m1 = back(nums, true, player1, player2 + temp);
        nums.insert(nums.begin(), temp);
        temp = nums.back();
        nums.pop_back();
        int m2 = back(nums, true, player1, player2 + temp);
        nums.push_back(temp);
        return std::min(m1, m2);
    }
}
};
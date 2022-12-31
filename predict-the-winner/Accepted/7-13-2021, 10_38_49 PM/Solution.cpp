// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        return minimax(nums, true, 0, 0) == 1;
        
    }
int minimax(std::vector<int> &nums, bool turn, int player1, int player2)
{

    if (nums.size() == 1)
    {
        if (turn)
        {
            if (player1 + nums[0] >= player2)
                return 1;
        }
        else if (player2 + nums[0] <= player1)
            return 1;

        return -1;
    }
    int temp = nums[0];
    int p1 = player1, p2 = player2;
    nums.erase(nums.begin());
    if (turn)
    {
        player1 += temp;
    }
    else
    {
        player2 += temp;
    }
    int m1 = minimax(nums, !turn, player1, player2);

    nums.insert(nums.begin(), temp);
    temp = nums.back();
    nums.pop_back();
    if (turn)
    {
        p1 += temp;
    }
    else
    {
        p2 += temp;
    }

    int m2 = minimax(nums, !turn, p1, p2);
    nums.push_back(temp);

    if (turn)
        return std::max(m1, m2);
    else
        return std::min(m1, m2);
}
};
// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = INT_MIN;
        while(left < right)
        {
            max_area = std::max(max_area, std::min(height[left], height[right]) * (right - left));
            if(height[left] < height[right])
            {
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }
};
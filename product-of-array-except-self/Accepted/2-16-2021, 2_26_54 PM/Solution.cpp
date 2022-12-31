// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ans;
        std::map<int, int> right_product;
        std::map<int, int> left_product;
        int product = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            left_product[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            right_product[i] = product;
            product *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            ans.push_back(left_product[i] * right_product[i]);
        }
        return ans;
    }
};
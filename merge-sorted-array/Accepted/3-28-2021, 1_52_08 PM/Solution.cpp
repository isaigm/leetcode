// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        std::vector<int> sorted;
        int l1 = 0, r1 = m - 1, l2 = m, r2 = m + n - 1;
        int temp = l1;
        while (l1 < r1 + 1 && l2 < r2 + 1)
        {
            if (nums1[l1] < nums1[l2])
            {
                sorted.push_back(nums1[l1]);
                l1++;
            }
            else
            {
                sorted.push_back(nums1[l2]);
                l2++;
            }
        }
        if (l1 == r1 + 1)
        {
            for (int i = l2; i <= r2; i++)
            {
                sorted.push_back(nums1[i]);
            }
        }
        else if (l2 == r2 + 1)
        {
            for (int i = l1; i <= r1; i++)
            {
                sorted.push_back(nums1[i]);
            }
        }
        for (int i = temp, j = 0; i <= r2; i++, j++)
        {
            nums1[i] = sorted[j];
        }
    }
   
};
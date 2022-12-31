// https://leetcode.com/problems/find-all-duplicates-in-an-array

#include <map>
#include <vector>
#include <iostream>
class Solution {
public:
   std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::map<int, int> counting;
        std::vector<int> duplicates;
        for(const auto &it : nums){
            counting[it]++;
        }
        for(auto &it: counting){
            if(it.second == 2){
                duplicates.push_back(it.first);
            }
        }
        return duplicates;

}
};
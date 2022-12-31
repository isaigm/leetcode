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
        for(const auto &it: counting){
            auto [key, value] = it;
            if(value == 2){
                duplicates.push_back(key);
            }
        }
        return duplicates;
    }
};
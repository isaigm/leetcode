// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> freq;
    std::vector<std::pair<int, int>> a;
    std::vector<int> res;
    for(const auto &it: nums){
        freq[it]++;
    }
    for(const auto &p: freq){
        a.push_back(p);
    }
    std::sort(a.begin(), a.end(), [](const auto &p1, const auto &p2){
        return p1.second > p2.second;
    });
    for(int i = 0; i < k; i++){
        res.push_back(a[i].first);
    }
    return res;
    }
};
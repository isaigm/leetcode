// https://leetcode.com/problems/h-index

class Solution {
public:
 int hIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end(), [](const auto &n1, const auto &n2){
        return n1 > n2;
    });
    for(size_t h = 0; h < citations.size(); h++){
        if(h + 1 >= (size_t) citations[h]) return h + 1;
    }
    return 0;
}
};
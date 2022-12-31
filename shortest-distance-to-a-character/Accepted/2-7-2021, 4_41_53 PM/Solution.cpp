// https://leetcode.com/problems/shortest-distance-to-a-character


class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c)
{
    auto min_distance = [](int idx, std::vector<int> &oc, std::vector<int> &res) {
        int min = INT_MAX;
        for (const auto &n : oc)
        {
            min = std::min(min, std::abs(idx - n));
        }
        if (min != INT_MAX)
        {
            res.push_back(min);
        }
    };
    std::vector<int> res;
    std::vector<int> oc;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            oc.push_back(i);
        }
    }
    for (size_t idx = 0; idx < s.size(); idx++)
    {
        if (s[idx] == c)
        {
            res.push_back(0);
        }
        else
        {
            min_distance(idx, oc, res);
        }
    }
    return res;
}
};
// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:
int minMutation(std::string start, std::string end, std::vector<std::string> &bank)
{
    auto hamming_distance = [](std::string &s1, std::string &s2)
    {
        int hamming_dist = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {

                hamming_dist++;
            }
        }
        return hamming_dist;
    };
    std::set<int> all_hamming_dists;

    int max_dist = hamming_distance(start, end);
    for(auto &gen: bank)
    {
        int hd = hamming_distance(end, gen);
        all_hamming_dists.insert(hd);
    }
    for(int i = 0; i < max_dist; i++)
    {
        if(all_hamming_dists.find(i) == all_hamming_dists.end())
        {
            return -1;
        }
    }

    return max_dist;
}
};
//AACCGGTT AAACGGTA
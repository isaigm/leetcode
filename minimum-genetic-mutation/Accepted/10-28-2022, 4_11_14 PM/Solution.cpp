// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:
int ans = INT32_MAX;
int hamming_distance(std::string &s1, std::string &s2)
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
}
void dfs(std::string &root, std::string &end,
         std::map<std::string, bool> &visited, std::vector<std::string> &bank, int &cnt)
{
    if (hamming_distance(root, end) == 0)
    {
        ans = std::min(ans, cnt);
        return;
    }
      visited[root] = true;
        cnt++;
        for (auto &gen : bank)
        {
            if (!visited[gen] && hamming_distance(gen, root) == 1)
            {
                dfs(gen, end, visited, bank, cnt);
            }
        }
        cnt--;
        visited[root] = false;
}
int minMutation(std::string start, std::string end, std::vector<std::string> &bank)
{
    std::vector<std::string> roots;
    std::map<std::string, bool> visited;
    std::string root = "";

    for (auto &gen : bank)
    {
        if (hamming_distance(gen, start) == 1)
        {
            roots.push_back(gen);
        }

        visited[gen] = false;
    }
    if (roots.size() == 0)
        return -1;
    for (auto &r : roots)
    {
        int cnt = 1;
        dfs(r, end, visited, bank, cnt);
    }
    if(ans != INT32_MAX) return ans;

    return -1;
}
};
//AACCGGTT AAACGGTA
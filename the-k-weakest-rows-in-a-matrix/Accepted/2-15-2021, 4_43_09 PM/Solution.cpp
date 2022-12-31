// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>> &mat, int k)
    {
        std::vector<std::pair<int, int>> rows;
        std::vector<int> ans;
        for (int i = 0; i < mat.size(); i++)
        {
            int soldiers = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j])
                {
                    soldiers++;
                }
                else
                {
                    break;
                }
            }
            rows.push_back(std::make_pair(i, soldiers));
        }
        std::sort(rows.begin(), rows.end(), [](const auto &p1, const auto &p2) {
            return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first);
        });
        for (int i = 0; i < k && i < rows.size(); i++)
        {
            ans.push_back(rows[i].first);
        }
        return ans;
    }
};
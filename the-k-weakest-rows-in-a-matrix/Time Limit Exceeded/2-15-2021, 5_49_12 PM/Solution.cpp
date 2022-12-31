// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
   std::vector<int> kWeakestRows(std::vector<std::vector<int>> &mat, int k)
{
    std::vector<std::pair<int, int>> rows;
    std::vector<int> ans;
    for (int i = 0; i < mat.size(); i++)
    {
        int last_one = 0;
        auto row = mat[i];
        int left = 0;
        int right = row.size();
        while (left < right)
        {
            int mid = right + (left - right) / 2;
            if (row[mid])
            {
                if (mid + 1 < row.size())
                {
                    if (row[mid + 1] == 0)
                    {
                        last_one = mid;
                        break;
                    }
                    else
                    {
                        left = mid;
                    }
                }
                else
                {
                    last_one = mid;
                    break;
                }
            }
            else
            {
                if (mid - 1 >= 0)
                {
                    if (row[mid - 1])
                    {
                        last_one = mid - 1;
                        break;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                else
                {
                    last_one = -1;
                    break;
                }
            }
        }

        rows.push_back(std::make_pair(i, last_one + 1));
    }
    std::sort(rows.begin(), rows.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
        return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first);
    });
    for (int i = 0; i < k && i < rows.size(); i++)
    {
        ans.push_back(rows[i].first);
    }

    return ans;
}
};
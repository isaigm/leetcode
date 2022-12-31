// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
   int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    int ans = 0;
    std::set<int> visited;
    int n = isConnected[0].size();
    for (int i = 0; i < n; i++)
    {
        std::stack<int> to_explore;
        if (visited.find(i) == visited.end())
        {
            ans++;
            to_explore.push(i);
            while (!to_explore.empty())
            {
                int curr_node = to_explore.top();
                visited.insert(curr_node);
                to_explore.pop();
                for (int j = 0; j < isConnected[curr_node].size(); j++)
                {
                    if (visited.find(j) == visited.end() && isConnected[curr_node][j])
                    {
                        visited.insert(j);
                        to_explore.push(j);
                    }
                }
            }
        }
    }
    return ans;
}
};
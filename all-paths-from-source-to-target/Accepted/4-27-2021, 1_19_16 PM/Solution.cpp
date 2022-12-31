// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<std::vector<int>> res;
        std::vector<int> ress;
        ress.push_back(0);
        dfs(0, graph.size() - 1, graph, ress, res);
        return res;
    }
    void dfs(int curr_node, int target, vector<vector<int>>& graph,      std::vector<int> &res,  std::vector<std::vector<int>> &ress)
    {
        if(curr_node == target)
        {
            ress.push_back(res);
            return;
        }
        for(auto adj: graph[curr_node])
        {
            res.push_back(adj);
            dfs(adj, target, graph, res, ress);
            res.pop_back();
        }
    }
};
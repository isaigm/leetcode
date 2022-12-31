// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> colors(graph.size(), - 1);
        std::queue<int> q;
        q.push(0);
        colors[0] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(graph[u].size() == 0) return false;
            for(int i = 0; i < graph[u].size(); i++)
            {
                int v = graph[u][i];
                if(colors[v] == -1)
                {
                    colors[v] = 1 - colors[u];
                    q.push(v);
                }else if(colors[v] == colors[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
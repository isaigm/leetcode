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
            for(int i = 0; i < graph[u].size(); i++)
            {
                if(colors[i] == -1)
                {
                    colors[i] = 1 - colors[u];
                    q.push(i);
                }else if(colors[i] == colors[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
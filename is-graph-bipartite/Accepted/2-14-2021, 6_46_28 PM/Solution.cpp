// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartiteUtil(vector<vector<int>>& graph, int src, std::vector<int> &colors) {
        std::queue<int> q;
        q.push(src);
        colors[src] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(graph[u].size() == 0){
                if(u < graph.size() - 1){
                    q.push(u + 1);
                    
                }
            }else{
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
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        std::vector<int> colors(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {
            if(colors[i] == -1)
            {
                if(!isBipartiteUtil(graph, i, colors)) return false;
            }
        }
        return true;
    }
};
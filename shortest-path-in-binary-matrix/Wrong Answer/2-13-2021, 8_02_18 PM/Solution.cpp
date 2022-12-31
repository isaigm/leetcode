// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid)
    {
        std::map<std::pair<int, int>, bool> visited;
        auto dim = grid.size();
        auto get_neighbours = [dim, &visited, &grid](int r, int c) {
            std::vector<std::pair<int, int>> neighbours;
            for (int i = r - 1; i <= r + 1; i++)
            {
                for (int j = c - 1; j <= c + 1; j++)
                {
                    if ((i == r && j == c) || i < 0 || j < 0 || i >= dim || j >= dim)
                    {
                        continue;
                    }
                    auto cell = std::make_pair(i, j);
                    if (grid[i][j] == 0)
                    {
                        neighbours.push_back(cell);
                    }
                }
            }
            return neighbours;
        };
        std::queue<std::pair<int, int>> nodes;
        std::map<std::pair<int, int>, std::pair<int, int>> prev;
        nodes.push(std::make_pair(0, 0));
        visited[std::make_pair(0, 0)] = true;
        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();
            auto neighbours = get_neighbours(node.first, node.second);
            for (const auto &next : neighbours)
            {
                if (!visited[next])
                {
                    nodes.push(next);
                    visited[next] = true;
                    prev[next] = node;
                }
            }
        }
        
        std::vector<std::pair<int, int>> path;
        
        auto step = std::make_pair(dim - 1, dim - 1);
        auto iter = prev.find(step);
        while (iter != prev.end())
        {
            path.push_back(iter->first);
            iter = prev.find(iter->second);
        }
        if(path.size() == 0) return -1;
        if (path[path.size() - 1].first == 0 && path[path.size() - 1].second == 0)
        {
            return path.size() + 1;
        }
        return -1;
    }
};
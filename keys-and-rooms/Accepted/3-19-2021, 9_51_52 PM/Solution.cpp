// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::queue<int> q;
        bool visited[rooms.size()];
        for(int i = 0; i < rooms.size(); i++)
        {
            visited[i] = false;
        }
        q.push(0);
        visited[0] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int j = 0; j < rooms[node].size(); j++)
            {
                if(!visited[rooms[node][j]])
                {
                    visited[rooms[node][j]] = true;
                    q.push(rooms[node][j]);
                }
            }
        }
        for(int i = 0; i < rooms.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
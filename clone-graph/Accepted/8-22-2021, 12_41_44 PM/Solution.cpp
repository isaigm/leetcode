// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        std::unordered_set<int> visited;
        std::queue<Node*> q;
        std::map<int, Node*> nodes;
        q.push(node);
        while(!q.empty())
        {
            auto n = q.front();
            
            visited.insert(n->val);
            nodes[n->val] = new Node(n->val);
            q.pop();
         
            for(const auto &c: n->neighbors)
            {
                if(c && visited.find(c->val) == visited.end())
                {
                    q.push(c);
                    visited.insert(c->val);
                }
          
            }
        }
        visited.clear();
        q.push(node);
        while(!q.empty())
        {
            auto n = q.front();
            
            visited.insert(n->val);
            
            q.pop();
            
            for(const auto &c: n->neighbors)
            {
                
                if(c && visited.find(c->val) == visited.end())
                {
                    q.push(c);
                     visited.insert(c->val);
                }
                nodes[n->val]->neighbors.push_back(nodes[c->val]);
          
            }
        }
        
        return nodes[1];
    }
};
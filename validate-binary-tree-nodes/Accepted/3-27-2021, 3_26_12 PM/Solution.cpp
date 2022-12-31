// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
  void dfs(unordered_set<int>& visited, int& curr_node, vector<int>& leftChild, vector<int>& rightChild) {
        if (visited.find(curr_node) != visited.end() || curr_node == -1) return;
        
        visited.insert(curr_node);
        dfs(visited, leftChild[curr_node], leftChild, rightChild);
        dfs(visited, rightChild[curr_node], leftChild, rightChild);                    
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // to dos
        // 1. find node that has not appeared from 0 to n-1, which will be the root
        // 2. dfs start from root, keep track of visited nodes
        // 3. if all nodes can be visited, return true, else false
        // time: o(n)
        // space: o(n)
        
        unordered_set<int> find_root;
        for (int i = 0; i < n; i++) {
            find_root.insert(i);
        }
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (find_root.find(leftChild[i]) == find_root.end()) return false;
                find_root.erase(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                if (find_root.find(rightChild[i]) == find_root.end()) return false;
                find_root.erase(rightChild[i]);
            }
        }
        
        if (find_root.size() != 1) {            
            return false;
        }
        
        int root = *find_root.begin();
        
        unordered_set<int> visited;
        
        dfs(visited, root, leftChild, rightChild);
        
        return visited.size() == n;                            
    }
};
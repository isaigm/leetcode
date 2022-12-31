// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    void cycle_detection(bool &flag, int &root, vector<int>& leftChild, vector<int>& rightChild, std::set<int> &nodes)
    {
        if(root != -1)
        {
            if(nodes.find(root) != nodes.end()){
                flag = true;
                return;
            }
            nodes.insert(root);
            cycle_detection(flag, leftChild[root], leftChild, rightChild, nodes);
            if(flag) return;
            cycle_detection(flag, rightChild[root], leftChild, rightChild, nodes); 
            if(flag) return;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        std::map<int, int> m;
        int roots = 0;
        for(int i = 0; i < n; i++)
        {
            if(leftChild[i] != -1)
            {
                m[leftChild[i]]++;
            }
            if(rightChild[i] != -1)
            {
                m[rightChild[i]]++;
            }
        }
        for(const auto &it: m)
        {
            if(it.second >= 2) return false;
    
        }
        for(int i = 0; i < n; i++)
        {
            if(m[i] == 0)
            {
                roots++;
            }
            if(roots > 1)
            {
                return false;
            }
            std::set<int> nodes;
            bool flag;
            cycle_detection(flag, i, leftChild, rightChild, nodes);
            if(flag) return false;
            
        }
        return true;
    }
};
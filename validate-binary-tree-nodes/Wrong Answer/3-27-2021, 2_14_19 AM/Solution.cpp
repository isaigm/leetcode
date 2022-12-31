// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        std::map<int, int> m;
        int root = 0;
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
                root++;
            }
            if(root > 1)
            {
                return false;
            }
        }
        return root == 1;
    }
};
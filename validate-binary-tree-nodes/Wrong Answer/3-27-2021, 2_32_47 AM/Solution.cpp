// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        std::map<int, int> m;
        std::map<int, std::pair<int, int>> childs;
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
            childs[i] = {leftChild[i], rightChild[i]};
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
            auto [left, right] = childs[i];
            if(left != -1){
                auto [l, r] = childs[left];
                if(l == i || r == i) return false;
            }
            if(right != -1){
                auto [l, r] = childs[right];
                if(l == i || r == i) return false;
            }
        }
        
        return root == 1;
    }
};
// https://leetcode.com/problems/evaluate-reverse-polish-notation

struct tree_node
{
    bool is_operator = false;
    char op;
    int value = 0;
    tree_node *left = nullptr;
    tree_node *right = nullptr;
};
bool is_operator(char c)
{
    return c == '-' || c == '+' || c == '*' || c == '/';
}
int eval(tree_node *root){
    int res = 0;
    if(root)
    {
        if(root->left == nullptr && root->right == nullptr) return root->value;
        if(root->is_operator)
        {
           switch (root->op) {
				case '+':
					res = eval(root->right) + eval(root->left);
					break;
				case '-':
					res = eval(root->left) - eval(root->right);
					break;
				case '*':
					res = eval(root->right) * eval(root->left);
					break;
				case '/':
					res = eval(root->left) / eval(root->right);
					break;
				}
        }
    }
    return res;
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<tree_node*> nodes;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].size() == 1 && is_operator(tokens[i][0]))
            {
                auto node = new tree_node();
                node->is_operator = true;
                node->op = tokens[i][0];
                node->right = nodes.top();
                nodes.pop();
                node->left = nodes.top();
                nodes.pop();
                nodes.push(node);
            }else
            {
                auto node = new tree_node();
                node->value = std::stoi(tokens[i]);
                nodes.push(node);
    
            }
        }
        tree_node *root = nodes.top();
        
        return eval(root);
    }
};
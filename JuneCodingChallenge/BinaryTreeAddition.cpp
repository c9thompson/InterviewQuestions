/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class solution{
public:
    int dfs(TreeNode* node, string val){
        if(!node) return stoi(val);

        val += to_string(node->val);
        return  node->left ? dfs(node->left, val) : 0 + 
                node->right ? dfs(node->right, val) : 0;
    }

    int countBinaryTree(TreeNode* root){ return root ? dfs(root, "") : 0; }
};
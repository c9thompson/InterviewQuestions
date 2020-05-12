/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

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
class Solution {
private:
    int max_;
    
    int max(int a, int b) { return a > b ? a : b; }
    int max(int a, int b, int c) { return max(a, max(b, c)); }
    
public:
    int traverse(TreeNode* node){
        int left = node->left ? traverse(node->left) : 0;
        int right = node->right ? traverse(node->right) : 0;
        
        int cross = max(node->val, left + right + node->val);
        int branch = max(node->val, node->val + (left > right ? left : right));
        if(cross > max_ || branch > max_) max_ = cross > branch ? cross : branch;
        
        return branch;
    }
    
    int maxPathSum(TreeNode* root){
        max_ = INT_MIN;
        traverse(root);
        return max_;
    }
};
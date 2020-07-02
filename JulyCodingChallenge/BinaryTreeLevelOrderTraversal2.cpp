/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
public:
    void lot(TreeNode* node, int level, vector<vector<int>>& output){
        if(!node) return;
        if(level >= output.size()) output.push_back(vector<int>());
        
        output[level].push_back(node->val);
        lot(node->left, level + 1, output);
        lot(node->right, level + 1, output);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        
        if(root) lot(root, 0, output);
        if(output.size() > 1) reverse(output.begin(), output.end());
        
        return output;
    }
};
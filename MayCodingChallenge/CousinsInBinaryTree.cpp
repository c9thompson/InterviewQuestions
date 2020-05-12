/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    bool traverse(TreeNode* root, const int& x, const int& y, int& depth, int& foundDepth){
        depth++;
        
        if(root->val == x || root->val == y){
            foundDepth = depth;
            return false;
        }else{
            int dl = depth, dr = depth;
            int fl = -1, fr = -1;
            
            bool l = root->left ? traverse(root->left, x, y, dl, fl) : false;
            bool r = root->right ? traverse(root->right, x, y, dr, fr) : false;
            
            if(l || r) return true;
            
            if(fl > 0 && fr > 0)           
                if(fl == fr) 
                    return fl > (depth + 1);
                else{
                    foundDepth = -1;
                    return false;
                }
            else{
                if(fl > 0)
                    foundDepth = fl;
                if(fr > 0)
                    foundDepth = fr;
                
                return false;
            }
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(x == root->val || y == root ->val) return false;
        
        int depth = 0;
        int foundDepth = -1;
        return traverse(root, x, y, depth, foundDepth);
    }
};
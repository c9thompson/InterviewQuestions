/*
Given a binary tree and an array, the task is to find if the given array sequence is present as a root to leaf path in given tree.
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
    bool traverse(TreeNode* node, vector<int> arr, int index){
        if(!node) return false;
            
        if(node->val == arr[index]){
            index++;
            if(index < arr.size())
                return traverse(node->left, arr, index) || traverse(node->right, arr, index);
            else
                return !(node->left || node->right);
        }else{
            return false;
        }
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {        
        return traverse(root, arr, 0);
    }
};
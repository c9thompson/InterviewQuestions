/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int findkthSmallest(TreeNode* node, int k, int& count, bool& flag){
        if(node->left || node->right){
            int val;
            if(node->left){
                val = findkthSmallest(node->left, k, count, flag);
                if(flag) return val;
            }
            
            count++;
            if(count == k){
                flag = true;
                return node->val;
            }
            
            if(node->right){
                int newCount = 0;
                val = findkthSmallest(node->right, k - count, newCount, flag);
                if(flag) return val;
                
                count += newCount;
            }
            
            return node->val;
        }else{
            count = 1;
            flag = (count == k);
            return node->val;
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        bool flag = false;
        int count = 0;
        return findkthSmallest(root, k, count, flag);
    }
};
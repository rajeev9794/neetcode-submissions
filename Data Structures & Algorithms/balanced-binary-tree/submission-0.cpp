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
    int computeHeight(TreeNode* root, bool &isBalance){
        if(root==NULL){
            return 0;
        }
        int leftTreeHeight = 1+computeHeight(root->left, isBalance);
        int rightTreeHeight = 1+computeHeight(root->right, isBalance);
        int computediff = abs(leftTreeHeight-rightTreeHeight);
        if(computediff>1){
            isBalance = false;
        }
        return max(leftTreeHeight,rightTreeHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        bool isBalance = true;
        computeHeight(root, isBalance);
        return isBalance;

    }
};

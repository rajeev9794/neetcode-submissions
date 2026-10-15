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
    int findDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(findDepth(root->left), findDepth(root->right));
    }
public:
    int maxDepth(TreeNode* root) {
        return findDepth(root);
    }
};

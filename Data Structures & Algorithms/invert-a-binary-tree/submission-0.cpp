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
    void invertTreeHelper(TreeNode* root){
        if(root==NULL){
            return;
        }
        TreeNode* currLeft = root->left;
        TreeNode* currRight = root->right;
        invertTree(currLeft);
        invertTree(currRight);
        root->left=currRight;
        root->right=currLeft;
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* invertedTreeRoot = root;
        invertTreeHelper(invertedTreeRoot);
        return invertedTreeRoot;
    }
};

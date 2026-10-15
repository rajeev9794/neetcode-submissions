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
    int computeDiameter(TreeNode* root, int &diameter){
        if(root==NULL){
            return 0;
        }
        int leftheight= 1+computeDiameter(root->left, diameter);
        int rightheight = 1+computeDiameter(root->right, diameter);
        int currDiameter = leftheight+rightheight-1;
        diameter = max(diameter, currDiameter);
        return max(leftheight, rightheight);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        computeDiameter(root,diameter);
        return diameter-1;
    }
};

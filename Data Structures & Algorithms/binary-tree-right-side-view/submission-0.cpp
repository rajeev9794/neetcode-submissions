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
    void computeRightView(vector<int> &v, TreeNode* root,int level){
        if(!root){
            return;
        }
        if(v.size()==level)
        v.push_back(root->val);
        computeRightView(v, root->right, level+1);
        computeRightView(v, root->left, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        computeRightView(v,root,0);
        return v;
    }
};

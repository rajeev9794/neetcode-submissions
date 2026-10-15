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
    void findTargetElement(TreeNode* root, int &currIndex, int requiredIndex, int &ans){
        if(root==NULL)return;
        findTargetElement(root->left, currIndex, requiredIndex, ans);
        currIndex++;
        //cout<<root->val<<endl;
        if(currIndex == requiredIndex){
            ans= root->val;
        }
        findTargetElement(root->right, currIndex, requiredIndex, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int currIndex =0;
        int ans =0;
        findTargetElement(root, currIndex, k, ans);
        return ans;
    }
};

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
    int maximumSum(TreeNode* root, int &mx){
        if(root==NULL){
            return 0;
        }

        int leftMax = max(maximumSum(root->left, mx),0);
        int rightMax = max(maximumSum(root->right,mx),0);

        //CurrTotal Including left and right child and adding root
        int currTotal = root->val+leftMax+rightMax;
        mx= max(mx, currTotal);
        //Considering only one from left or right
        int tempTotal = root->val + max(leftMax, rightMax);
        return tempTotal;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int mx= root->val;
        maximumSum(root, mx);
        return mx;


    }
};

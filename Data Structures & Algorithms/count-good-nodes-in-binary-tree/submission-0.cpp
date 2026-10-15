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
    int findgoodNodes(TreeNode* root, int currMax){
        if(root==NULL){
            return 0;
        }
        int ans =0;
        if(currMax<=root->val){
            currMax = root->val;
            ans++;
        }

        int leftgoodNodes = findgoodNodes(root->left, currMax);
        int rightgoodNodes = findgoodNodes(root->right, currMax);
        return ans+leftgoodNodes+rightgoodNodes; 
    }
public:
    int goodNodes(TreeNode* root) {
        int ans=1;
        if(root==NULL){
            return 0;
        }
        int currMax = root->val;
        ans = ans+findgoodNodes(root->left, currMax);
        ans+=findgoodNodes(root->right, currMax);
        return ans;
    }
};

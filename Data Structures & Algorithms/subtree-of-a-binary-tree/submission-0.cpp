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
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(root1 ==NULL && root2 ==NULL){
            return true;
        }
        else if(root1!=NULL && root2!=NULL){
            return root1->val == root2->val && isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
        }
        else{
            return false;
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool computeFromParent = false;
        if(root==NULL && subRoot==NULL){
            return true;
        }
        else if(root!=NULL && subRoot!=NULL){
            if(root->val==subRoot->val){
                computeFromParent= isSame(root, subRoot);
            }
            
            return computeFromParent || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
        else{
            return false;
        }
    }
};

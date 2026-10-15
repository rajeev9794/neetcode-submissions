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
    bool isValidBSTConsideringMinMax(TreeNode* root,int lowerRange, int upperRange){
        if(root==NULL){
            return true;
        }
        int parentValue = root->val;
        //cout<<parentValue<<endl;
        if(lowerRange >= parentValue || upperRange <= parentValue){
            return false;
        }
        if(root->left && parentValue <= root->left->val){
            return false;
        }

        if(root->right && parentValue >= root->right->val){
            return false;
        }
        
        return isValidBSTConsideringMinMax(root->left, lowerRange, parentValue) && isValidBSTConsideringMinMax(root->right, parentValue, upperRange);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int parentValue = root->val;
        if(root->left && parentValue <= root->left->val){
            return false;
        }

        if(root->right && parentValue >= root->right->val){
            return false;
        }
        
        
        return isValidBSTConsideringMinMax(root->left, INT_MIN, root->val) && isValidBSTConsideringMinMax(root->right, root->val, INT_MAX);
    }
};

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
    void computeLevelOrder(vector<vector<int>> &ans, int level, TreeNode* node){
        if(!node)
        return;
        if(level+1>ans.size()){
            ans.resize(level+1);
        }
        ans[level].push_back(node->val);
        computeLevelOrder(ans, level+1,node->left);
        computeLevelOrder(ans, level+1,node->right);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        computeLevelOrder(ans, 0, root);
        return ans;
    }
};

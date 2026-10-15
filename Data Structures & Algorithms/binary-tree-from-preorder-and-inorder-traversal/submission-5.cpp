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
    int preIndex=0;
    unordered_map<int,int>index;

    TreeNode* constructTree(vector<int> &preorder, int l, int r){
        if(l>r){
            return NULL;
        }
        if(preIndex>=preorder.size())
        return NULL;

        int rootVal = preorder[preIndex];
        TreeNode* currNode = new TreeNode(rootVal);
        preIndex++;
        if(l==r){
            return currNode;
        }
        //cout<<rootVal<<endl;

        int mid = index[rootVal];
        currNode->left = constructTree(preorder, l,mid-1);
        currNode->right = constructTree(preorder, mid+1,r);
        return currNode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        if(n==0){
            return NULL;
        }
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }

        return constructTree(preorder,0,n-1);


    }
};

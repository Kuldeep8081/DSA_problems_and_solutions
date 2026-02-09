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
public:
    void inOrder(TreeNode*root,vector<int>&sortedNodes){

        if(!root)
        return ;

        inOrder(root->left,sortedNodes);
        sortedNodes.push_back(root->val);
        inOrder(root->right,sortedNodes);
    }
    TreeNode*solve(vector<int>&arr,int l,int r){
        if(l>r)
        return nullptr;
        int mid=l+(r-l)/2;

        TreeNode* root=new TreeNode(arr[mid]);
        root->left=solve(arr,l,mid-1);
        root->right=solve(arr,mid+1,r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>sortedNodes;
        inOrder(root,sortedNodes);

        int n=sortedNodes.size();

        return solve(sortedNodes,0,n-1);
    }
};
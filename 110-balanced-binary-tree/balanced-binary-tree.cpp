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
    pair<int,bool> solve(TreeNode*root,int level){
        
        if(!root){
            return {level,true};
        }

        pair<int,bool>left=solve(root->left,level+1);
        pair<int,bool>right=solve(root->right,level+1);

        return {max(left.first,right.first), left.second&&right.second && abs(left.first-right.first)<=1};
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        return true;
        
        pair<int,bool>p=solve(root,0);

        return p.second;
    }
};
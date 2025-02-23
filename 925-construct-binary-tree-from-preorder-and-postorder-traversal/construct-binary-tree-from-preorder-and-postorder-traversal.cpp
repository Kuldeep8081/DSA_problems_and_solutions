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
    
    TreeNode*constructTreeUtil(vector<int>&pre,vector<int>&post,int &preIndex,int l,int h,int size){

        if(preIndex>=size || l>h)
        return nullptr;

        TreeNode*root=new TreeNode(pre[preIndex]);

        preIndex++;

        if(l==h)
        return root;


        int i;
        for(i=l;i<=h;i++){
            if(pre[preIndex]==post[i])
            break;
        }

        if(i<=h){
            root->left=constructTreeUtil(pre,post,preIndex,l,i,size);

            root->right=constructTreeUtil(pre,post,preIndex,i+1,h-1,size);
        }

        return root;
    }
    
    TreeNode*constructTree(vector<int>&pre,vector<int>&post){

        int preIndex=0;
        int size=pre.size();

        return constructTreeUtil(pre,post,preIndex,0,size-1,size);
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        TreeNode*root=constructTree(preorder,postorder);

        return root;
    }
};
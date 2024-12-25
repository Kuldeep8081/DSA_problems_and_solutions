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
    vector<int> BFS(TreeNode*root){
        vector<int>ans;
        if(!root){
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            TreeNode* curr=q.front();
            int maxi=curr->val;
            for(int i=0;i<size;i++){
                curr=q.front();
                q.pop();
                maxi=max(maxi,curr->val);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            ans.push_back(maxi);
            
        }

        return ans;

    }
    vector<int> largestValues(TreeNode* root) {
        
        return BFS(root);
    }
};
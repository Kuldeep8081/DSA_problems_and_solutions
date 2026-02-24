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
    void solve(TreeNode*root,string s,vector<string>&vec){

        if(!root->left && !root->right){
            s.push_back('0'+root->val);
            vec.push_back(s);
            return ;
        }

        s.push_back('0'+root->val);

        if(root->left){
            solve(root->left,s,vec);
        }

        if(root->right){
            solve(root->right,s,vec);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string>vec;
        solve(root,"",vec);
        int ans=0;
        for(string &str : vec){
            int mul=1;
            for(int i=str.size()-1;i>=0;i--){
                ans+=(str[i]-'0')*mul;
                mul*=2;
            }
        }

        return ans;
    }
};
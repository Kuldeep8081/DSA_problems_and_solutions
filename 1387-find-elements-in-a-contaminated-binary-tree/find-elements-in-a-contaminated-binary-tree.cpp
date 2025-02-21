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
class FindElements {
public:

    unordered_map<int,bool>mp;

    void solve(TreeNode*&root){

        if(root->left){

            int ele=2*root->val+1;
            root->left->val=ele;
            mp[ele]=true;

            solve(root->left);
        }

        if(root->right){
            int ele=2*root->val+2;
            root->right->val=ele;
            mp[ele]=true;
            solve(root->right);
        }


    }
    FindElements(TreeNode* root) {
        
        root->val=0;
        mp[root->val]=true;

        solve(root);
    }
    
    bool find(int target) {
        
        if(mp[target])
        return true;

        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
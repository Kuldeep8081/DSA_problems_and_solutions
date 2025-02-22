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
    TreeNode* recoverFromPreorder(string traversal) {
        
        unordered_map<int,TreeNode*>mp;

        string str="";
        
        int j=0;
        while(j<traversal.size() && traversal[j]!='-'){
            str.push_back(traversal[j]);
            j++;
        }

        int v=stoi(str);


        TreeNode*root=new TreeNode(v);
        mp[0]=root;
        
        int cnt=0;
        for(int i=j;i<traversal.size();i++){
            
            if(traversal[i]=='-'){
                cnt++;
            }else{
                
                int level=cnt-1;
                TreeNode* node=mp[level];

                string str="";
               
                while(i<traversal.size() && traversal[i]!='-'){
                    str.push_back(traversal[i]);
                    i++;
                }

                i--;

                int v=stoi(str);
                TreeNode*newNode=new TreeNode(v);
                if(!node->left)
                {
                    node->left=newNode;
                }else{
                    node->right=newNode;
                }

                mp[cnt]=newNode;

                cnt=0;

            }

        }

        return root;
    }
};
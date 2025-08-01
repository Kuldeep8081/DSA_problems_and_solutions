class Solution {
public:
    vector<vector<int>> generate(int numRows) {


        vector<vector<int>>ans;

        vector<int>vals;

        if(ans.size()==0)
        vals.push_back(1);

        ans.push_back(vals);

        for(int i=0;i<numRows-1;i++)
        {
            vector<int>vals;
            vals.push_back(1);
            for(int prev=0;prev<ans[i].size()-1;prev++){
                vals.push_back(ans[i][prev]+ans[i][prev+1]);
            }
            vals.push_back(1);
            ans.push_back(vals);

        }

        return ans;
    }
};
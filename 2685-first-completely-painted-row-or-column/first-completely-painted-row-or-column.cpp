class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        
        
        vector<int>row(m);
        vector<int>col(n);

        for(int i=0;i<arr.size();i++){
            pair<int,int>p=mp[arr[i]];
            row[p.first]++;
            col[p.second]++;

            if(row[p.first]==n || col[p.second]==m)
            return i;
        }

        return 0;
    }
};
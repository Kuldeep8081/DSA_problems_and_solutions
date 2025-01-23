class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1}};
    int countServers(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;

        //Applying DFS
        unordered_map<int,int>row;
        unordered_map<int,int>col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

               if(grid[i][j]==1){
                row[i]++;
                col[j]++;
               }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (row[i]>1 || col[j]>1)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
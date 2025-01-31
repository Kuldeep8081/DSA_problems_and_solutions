class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int n;
    int DFS(vector<vector<int>>&grid,int i,int j, int id){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1)
        return 0;

        grid[i][j]=id;
        int size=1;

        for(vector<int>&dir : dir){
            int i_=i+dir[0];
            int j_=j+dir[1];

            size+=DFS(grid,i_,j_,id);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        
        n=grid.size();

        int maxArea=0;

        int id=2;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=DFS(grid,i,j,id);
                    maxArea=max(maxArea,size);
                    mp[id]=size;
                    id++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>uniqueIds;
                    for(auto &dir : dir){
                        int i_=i+dir[0];
                        int j_=j+dir[1];
                        if(i_>=0 && i_<n && j_>=0 && j_<n && grid[i_][j_]!=0){
                            uniqueIds.insert(grid[i_][j_]);
                        }
                    }

                    int overallsize=1;

                    for(auto &id : uniqueIds){
                        overallsize+=mp[id];
                    }

                    maxArea=max(maxArea,overallsize);
                }
            }
        }

        return maxArea==0?(n*n):maxArea;
    }
}; 
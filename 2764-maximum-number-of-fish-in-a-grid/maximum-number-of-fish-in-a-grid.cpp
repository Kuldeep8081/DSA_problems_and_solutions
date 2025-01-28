class Solution {
public:
    
    vector<pair<int,int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
    int findMaxFish(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]>0){
                    stack<pair<int,int>>q;
                    q.push({i,j});
                    int sum=0;
                    while(!q.empty()){
                        pair<int,int>p=q.top();
                        q.pop();
                        int i_=p.first;
                        int j_=p.second;
                        sum+=grid[i_][j_];
                        grid[i_][j_]=0;
                        for(auto pa : dir){
                            int newi=i_+pa.first;
                            int newj=j_+pa.second;

                            if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]>0){
                                q.push({newi,newj});
                            }
                        }
                    }

                    ans=max(ans,sum);
                }
            }
        }

        return ans;
    }
};
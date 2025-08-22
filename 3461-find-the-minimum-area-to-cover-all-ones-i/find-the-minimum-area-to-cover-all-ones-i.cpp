class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int top=-1;
        int left=-1;
        int right;
        int bottom;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==1){

                    if(top==-1)
                    bottom=i;
                    top==-1?top=i:bottom=i;
                }
            }
        }

        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                
                if(grid[j][i]==1){

                    if(left==-1)
                    right=i;
                    left==-1?left=i:right=i;
                }
            }
        }

        return (right-left+1)*(bottom-top+1);


    }
};
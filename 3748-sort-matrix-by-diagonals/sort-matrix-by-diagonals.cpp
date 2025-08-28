class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();

        for(int i=n-1;i>=0;i--){
            int k=i,j=0;
            vector<int>vec;
            while(k<n && j<n){
               vec.push_back(grid[k][j]);
               k++;
               j++;
            }

            sort(vec.begin(),vec.end(),greater<int>());

            k=i;
            j=0;

            for(int val : vec){
                grid[k][j]=val;
                k++;
                j++;
            }
        }

        for(int j=1;j<n;j++){
            int i=0,k=j;
            vector<int>vec;
            while(i<n && k<n){
                vec.push_back(grid[i][k]);
                i++;
                k++;
            }

            sort(vec.begin(),vec.end());

            i=0;
            k=j;

            for(int val : vec){
                grid[i][k]=val;
                i++;
                k++;
            }
        }

        return grid;
    }
};
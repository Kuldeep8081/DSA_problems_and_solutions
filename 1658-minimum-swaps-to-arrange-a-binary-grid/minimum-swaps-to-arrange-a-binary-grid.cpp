class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=1;j--){
               
               if(grid[i][j]==1)
               break;
               cnt++;
            }
            arr[i]=cnt;
        }

        int steps=0;

        for(int i=0;i<n;i++){
            int j=i;
            while(j<n){
                if(arr[j]>=(n-i-1)){
                    j++;
                    break;
                }
                j++;
            }
            j--;

            while(j>i){
                swap(arr[j-1],arr[j]);
                j--;
                steps++;
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]<n-i-1)
            return -1;
        }

        return steps;

        
    }
};
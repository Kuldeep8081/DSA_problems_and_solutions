class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
               mat[i][j]=mat[i][j-1]+mat[i][j];
            }
        }

        int maxSide=min(m,n);

        for(int side=maxSide;side>=1;side--){
            for(int i=0;i<m-side+1;i++){
                for(int j=0;j<n-side+1;j++){
                    long long sum=0;
                    for(int k=0;k<side;k++){
                        sum+=(long long) (mat[i+k][j+side-1]-(j>0?mat[i+k][j-1]:0));
                        if(sum>threshold)
                        break;
                    }
                    
                    if(sum<=threshold)
                    return side;
                }
            }
        }

        return 0;
    }
};
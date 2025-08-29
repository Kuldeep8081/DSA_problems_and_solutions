class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long odd1;
        long long even1;
        long long odd2;
        long long even2;

        if(m%2==0){
           odd1=m/2;
           even1=m/2;
        }else{
            even1=(m-1)/2;
            odd1=(m+1)/2;
        }
        if(n%2==0){
           odd2=n/2;
           even2=n/2;
        }else{
            even2=(n-1)/2;
            odd2=(n+1)/2;
        }

        long long ans =(even1*odd2)+(even2*odd1);

        return ans;
    }
};
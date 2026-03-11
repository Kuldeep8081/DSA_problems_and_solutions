class Solution {
public:
    int bitwiseComplement(int n) {
        int mul=1;
        int ans=0;
        if(n==0)
        return 1;
        while(n){
            int last=(((n&1)==0)?1:0);
            ans+=last*mul;
            mul*=2;
            n=n>>1;
        }

        return ans;
    }
};
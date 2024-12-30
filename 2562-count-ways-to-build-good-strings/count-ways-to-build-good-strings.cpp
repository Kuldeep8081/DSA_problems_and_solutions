class Solution {
public:
    int mod=1e9+7;
    int l;
    int h;
    int numzero;
    int numone;
    long long cnt=0;
    vector<int>dp;
    int solve(int len){

        if(len>h){
            return 0;
        }

        if(dp[len]!=-1) return dp[len];
        int got=0;
        if(len>=l && len<=h){
            got=1;
        }
        
        int addZero=solve((len+numzero)%mod);
        int addOne=solve((len+numone)%mod);

        return dp[len]=(got+addOne+addZero)%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        l=low;
        h=high;
        numzero=zero;
        numone=one;
        int len=0;
        dp.assign(100001,-1);
        return solve(len);
    }
};
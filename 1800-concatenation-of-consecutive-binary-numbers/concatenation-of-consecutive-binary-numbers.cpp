class Solution {
public:
    int mod=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int val=1;val<=n;val++){
            int cnt=0;
            int num=val;
           while(num){
            cnt++;
            num>>=1;
           }
           ans=(ans<<cnt)+val;
           ans%=mod;
        }
        return ans;
    }

};
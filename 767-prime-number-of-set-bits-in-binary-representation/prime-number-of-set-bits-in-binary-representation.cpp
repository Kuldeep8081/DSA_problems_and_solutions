class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int val =left;val<=right;val++){
            int cnt=0;
            int num=val;
            while(num){
                cnt+=num&1==1?1:0;
                num>>=1;
            }

            bool flag=true;
            
            if(cnt==1){
                flag=false;
            }

            for(int i=2;i<=sqrt(cnt);i++){
                 if(cnt%i==0){
                    flag=false;
                    break;
                 }
            }
            if(flag){
                ans++;
            }
        }

        return ans;
    }
};
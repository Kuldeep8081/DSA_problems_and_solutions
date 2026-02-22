class Solution {
public:
    int binaryGap(int n) {
        int maxDis=0;
        int cnt=0;
        bool flag=false;
        while(n){
          int lastDigit=n&1;

          if(lastDigit){
            flag=true;
          }

          if(lastDigit){
             maxDis=max(maxDis,cnt);
             cnt=1;
          }else if(flag){
            cnt++;
          }
          n>>=1;
        }

        return maxDis;
    }
};
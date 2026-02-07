class Solution {
public:
    int minimumDeletions(string s) {
        
        bool flag=false;

        int cntB=0;
        int cntA=0;
        int ans=0;
        int ans2=0;

        for(int i=0;i<s.size();i++){
           
           if(s[i]=='b' && cntB==0 && flag==false){
               flag=true;
               cntB++;
           }else if(flag && s[i]=='b'){
               cntB++;
           }else if(flag && s[i]=='a'){
               cntA++;
               if(cntB<=cntA){
                  flag=false;
                  ans+=cntB;
                  ans2=0;
                  cntA=0;
                  cntB=0;
               }else{
                ans2=cntA;
               }
           }
        }

        

        return ans+ans2;
    }
};
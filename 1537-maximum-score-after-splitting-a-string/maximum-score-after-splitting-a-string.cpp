class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int oneCnt=0;
        for(int i=1;i<n;i++){

            if(s[i]=='1')
            oneCnt++;
        }

        int zeroCnt=0;
        int one=oneCnt;
        if(s[0]=='0'){
            zeroCnt++;
        }
        int ans=max(oneCnt,zeroCnt);
        for(int i=1;i<n-1;i++){

            if(s[i]=='0'){
                zeroCnt++;
            }

            ans=max(ans,oneCnt+zeroCnt);
            if(s[i]=='1')
            oneCnt--;

            
        }

        ans=max(ans,oneCnt+zeroCnt);


        return ans;

    }
};
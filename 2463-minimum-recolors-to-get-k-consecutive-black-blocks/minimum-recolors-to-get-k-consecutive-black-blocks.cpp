class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int bcnt=0;
        int wcnt=0;
        int len=blocks.size();

        int ans=INT_MAX;
        int cnt=0;
        for(int i=0;i<len;i++){
            
            if(cnt<k)
            {
                if(blocks[i]=='W')
                {wcnt++;}
                cnt++;
            }else{

                ans=min(ans,wcnt);
                if(blocks[i-k]=='W' && blocks[i]!='W'){
                    wcnt--;
                }else if(blocks[i-k]!='W' && blocks[i]=='W'){
                    wcnt++;
                }
            }

            
        }

        ans=min(ans,wcnt);

        return ans;
    }
};
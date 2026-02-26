class Solution {
public:
    int numSteps(string s) {
        int steps=0;
        while(s.size()!=1){
            steps++;
            if(s.back()=='1'){
                int carry=1;
                int i=s.size()-1;
                while(carry==1 && i>=0){
                   if(s[i]=='1'){
                    s[i]='0';
                   }else{
                    s[i]='1';
                    carry=0;
                   }
                   i--;
                }
                if(carry){
                    s="1"+s;
                }
            }else{
               s.pop_back();
            }
        }

        return steps;
    }
};
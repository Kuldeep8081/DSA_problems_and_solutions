class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        bool flag=true;

        for(char&ch: s){
            if(ch=='0'){
                flag=true;
            }else if(ch=='1' && flag==true){
                cnt++;
                flag=false;
            }
        }

        return cnt==1;
    }
};
class Solution {
public:

    string solve(int cnt,int n,string s){
        if(cnt==n)
        return s;
        
        int count=0;
        int size=s.length();
        for(int i=0;i<size;i++){

            count++;
            if((i==size-1) || (i<(size-1) && (s[i]!=s[i+1]) )){
               s.push_back(count+'0');
               s.push_back(s[i]);
               count=0;

            }
        }

        return solve(cnt+1,n,s.substr(size));
    }
    string countAndSay(int n) {
        
        return solve(1,n,"1");
    }
};
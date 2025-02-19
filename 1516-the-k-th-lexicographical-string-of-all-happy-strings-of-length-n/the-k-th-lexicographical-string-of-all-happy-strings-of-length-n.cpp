class Solution {
public:

    string solve(int n,int k,string &str,string s,int &cnt){
        
        if(s.length()==n){
            cnt++;

            if(cnt==k)
            return s;

           return "";
        }

        for(int i=0;i<=2;i++){

            if(s.size()==0 || s.back()!=str[i]){

                string str1=solve(n,k,str,s+str[i],cnt);

                if(str1.size())
                return str1;
            }

        }

        return "";

    }
    string getHappyString(int n, int k) {
        
        string str="abc";
        string s="";

        int cnt=0;

        return solve(n,k,str,s,cnt);
    }
};
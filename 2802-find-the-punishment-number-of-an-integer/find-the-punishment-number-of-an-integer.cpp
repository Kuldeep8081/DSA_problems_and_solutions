class Solution {
public:


    bool solve(int ind,const string &str,const int &val,int sum){
        
        if(sum>val)
        return false;

        if((ind==str.length()) && (val==sum))
        return true;


        for(int i=1;i<str.length()-ind+1;i++){
            string s=str.substr(ind,i);

            int strval=stoi(s);

            if(solve(ind+i,str,val,sum+strval))
            return true;
        }

        return false;

    }


    int punishmentNumber(int n) {
        
        int ans=0;
        for(int i=1;i<=n;i++){
            string str=to_string(i*i);

            if(solve(0,str,i,0))
            ans+=i*i;

        }

        return ans;
    }
};
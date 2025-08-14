class Solution {
public:
    string largestGoodInteger(string num) {
        
        unordered_map<char,bool>mp;
        
        int cnt=0;
        for(int i=1;i<num.size();i++){

            if(mp[num[i]])
            continue;

           if(num[i]==num[i-1]){
            cnt++;
           }else{
            cnt=0;
           }

           if(cnt==2)
           {
            mp[num[i]]=true;
           }
        }

        char maxDigit=0;
        bool flag=false;

        for(auto m : mp){
            if(m.second){
            maxDigit=max(maxDigit,m.first);
            flag=true;}
        }

        string ans="";

        if(flag)
        {
            for(int i=0;i<3;i++){
                ans.push_back(maxDigit);
            }
        }

        return ans;

    }
};
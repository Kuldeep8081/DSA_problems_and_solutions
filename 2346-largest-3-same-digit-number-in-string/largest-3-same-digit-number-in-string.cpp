class Solution {
public:
    string largestGoodInteger(string num) {
        
        unordered_map<char,bool>mp;
        string ans="";
        for(int i=0;i<num.size()-2;i++){
            
            if(mp[num[i]])
            continue;


            char digit=num[i];
            string str="";
            str.push_back(digit);
            for(int j=i+1;j<=i+2;j++)
            {
                if(digit==num[j])
                str.push_back(digit);
                else
                break;
            }

            if(str.size()==3 && ans.size()==0)
            {
                mp[digit]=true;
                ans=str;
                continue;
            }

            if(str.size()==3 && ans[0]<digit){
               ans=str;
               mp[digit]=true;
            }
        }

        return ans;
    }
};
class Solution {
public:
    unordered_map<string ,bool>mp;
    
    string solve(string &str,string s,const int n){

        if(s.size()==n){

            if(!mp[s])
            return s;

            return "";
        }

        for(int i=0;i<=1;i++){

            string str1=solve(str,s+str[i],n);

            if(str1.size())
            return str1;
        }

        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        
        int n=nums.size();
        for(string str : nums){
            mp[str]=true;
        }

        string str="01";
        string s="";

        return solve(str,s,n);
    }
};